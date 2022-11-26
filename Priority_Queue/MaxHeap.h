#include "HeapNode.h"       // HeapNode.h ������ ������.(���� ����)
#define MAX_ELEMENT 200     // MAX_ELEMENT ���� 200 ���� ������.
class MaxHeap
{   // �迭�� �̿��� �ִ� �� Ŭ����
    HeapNode node[MAX_ELEMENT];
    int size;

public:
    MaxHeap() : size(0) {}      // ������ & Member Initializer
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT - 1; }

    HeapNode &getParent(int i) { return node[i / 2]; }      // �θ� ���
    HeapNode &getLeft(int i) { return node[i * 2]; }        // ���� �ڽ� ���
    HeapNode &getRight(int i) { return node[i * 2 + 1]; }   // ������ �ڽ� ���

    void insert(int key)    // ���� key ���� ���� ���ο� ��带 �����ϴ� insert(int key) �Լ�
    {
        if (isFull())   // ���� ������ ���
            return;     // return
        int i = ++size; // �׷��� ������ ������ �� ũ���� ��ġ���� ������.

        // Ʈ���� �Ž��� �ö󰡸鼭 �θ� ���� ���ϴ� ����
        while (i != 1 && key > getParent(i).getKey())   
        {   // ��Ʈ ���(i=1)�� �ƴϰ�, key ���� �θ� ��庸�� ũ��
            node[i] = getParent(i);     // �θ� ��带 �ڽ��� ���� �������
            i /= 2;     // �� ���� ���� �����.
        }
        node[i].setKey(key);        // ���� ��ġ�� �����͸� ������.
    }

    HeapNode remove()       // ���� ��Ʈ ��带 ��ȯ�ϰ� ���� �籸���ϴ� remove() �Լ�
    {
        if (isEmpty())      // ��������� NULL �� ��ȯ
            return NULL;
        HeapNode item = node[1];        // ��Ʈ ���(���� ���)
        HeapNode last = node[size--];   // ���� ������ ���
        int parent = 1;     // ������ ����� ��ġ�� ��Ʈ ����� ��ġ�� ������.
        int child = 2;      // ��Ʈ ����� ���� �ڽ� ���
        while (child <= size)       // �� Ʈ���� ����� �ʴ� ���� �ݺ���.
        {   // ���� ����� �ڽ� ��� �� �� ū �ڽ� ��带 ã��.
            if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
                child++;

            if (last.getKey() >= node[child].getKey())
                break;      // ������ ��尡 �� ū �ڽĺ��� ũ�� break;

            node[parent] = node[child];     // �� �ܰ� �Ʒ��� �̵���.
            parent = child;
            child *= 2;
        }

        node[parent] = last;        // ������ ��带 ���� ��ġ�� ������.
        return item;        // ��Ʈ ��� ��ȯ
    }

    HeapNode find() { return node[1]; }

    void display(){
        for(int i=1,level=1;i<=size;i++){
            if(i==level){
                printf("\n");
                level *= 2;
            }
            node[i].display();
        }
        printf("\n----------------------------------------");
    }
};
