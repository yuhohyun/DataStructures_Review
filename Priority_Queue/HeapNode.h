#include <cstdio>
class HeapNode
{   // ���� ������ Node Ŭ����
    int key;

public:
    HeapNode(int k = 0) : key(k) {}     // ������ & Member Initializer
    void setKey(int k) { key = k; }     // key�� k ������ �����ϴ� setKey(int k) �Լ�
    int getKey() { return key; }        // key ���� ��ȯ�ϴ� getKey() �Լ�
    void display() { printf("%4d", key); }      // display() �Լ�
};