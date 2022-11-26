#include <cstdio>
class HeapNode
{   // 힙에 저장할 Node 클래스
    int key;

public:
    HeapNode(int k = 0) : key(k) {}     // 생성자 & Member Initializer
    void setKey(int k) { key = k; }     // key를 k 값으로 설정하는 setKey(int k) 함수
    int getKey() { return key; }        // key 값을 반환하는 getKey() 함수
    void display() { printf("%4d", key); }      // display() 함수
};