#include "HeapNode.h"       // HeapNode.h 파일을 포함함.(포함 관계)
#define MAX_ELEMENT 200     // MAX_ELEMENT 값을 200 으로 정의함.
class MaxHeap
{   // 배열을 이용한 최대 힙 클래스
    HeapNode node[MAX_ELEMENT];
    int size;

public:
    MaxHeap() : size(0) {}      // 생성자 & Member Initializer
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT - 1; }

    HeapNode &getParent(int i) { return node[i / 2]; }      // 부모 노드
    HeapNode &getLeft(int i) { return node[i * 2]; }        // 왼쪽 자식 노드
    HeapNode &getRight(int i) { return node[i * 2 + 1]; }   // 오른쪽 자식 노드

    void insert(int key)    // 힙에 key 값을 갖는 새로운 노드를 삽입하는 insert(int key) 함수
    {
        if (isFull())   // 힙이 가득찬 경우
            return;     // return
        int i = ++size; // 그렇지 않으면 증가된 힙 크기의 위치에서 시작함.

        // 트리를 거슬러 올라가면서 부모 노드와 비교하는 과정
        while (i != 1 && key > getParent(i).getKey())   
        {   // 루트 노드(i=1)가 아니고, key 값이 부모 노드보다 크면
            node[i] = getParent(i);     // 부모 노드를 자신의 노드로 끌어내리고
            i /= 2;     // 한 레벨 위로 상승함.
        }
        node[i].setKey(key);        // 최종 위치에 데이터를 복사함.
    }

    HeapNode remove()       // 힙에 루트 노드를 반환하고 힙을 재구성하는 remove() 함수
    {
        if (isEmpty())      // 비어있으면 NULL 값 반환
            return NULL;
        HeapNode item = node[1];        // 루트 노드(꺼낼 요소)
        HeapNode last = node[size--];   // 힙의 마지막 노드
        int parent = 1;     // 마지막 노드의 위치를 루트 노드의 위치로 생각함.
        int child = 2;      // 루트 노드의 왼쪽 자식 노드
        while (child <= size)       // 힙 트리를 벗어나지 않는 동안 반복함.
        {   // 현재 노드의 자식 노드 중 더 큰 자식 노드를 찾음.
            if (child < size && getLeft(parent).getKey() < getRight(parent).getKey())
                child++;

            if (last.getKey() >= node[child].getKey())
                break;      // 마지막 노드가 더 큰 자식보다 크면 break;

            node[parent] = node[child];     // 한 단계 아래로 이동함.
            parent = child;
            child *= 2;
        }

        node[parent] = last;        // 마지막 노드를 최종 위치에 저장함.
        return item;        // 루트 노드 반환
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
