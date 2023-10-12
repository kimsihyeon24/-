#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;



HeapType* create()
{
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h)
{
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item)
{
	int i;
	i = ++(h->heap_size);


	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
	
}

element delete_max_heap(HeapType* h)
{
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key) < h->heap[child + 1].key)
			child++;
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	
	return item;
}

void print_heap_level_order(HeapType* h) {
	if (h->heap_size == 0) {
		printf("힙이 비어 있습니다.\n");
		return;
	}

	printf("힙 요소 (레벨 순서대로): ");
	for (int i = 1; i <= h->heap_size; i++) {
		printf("%d ", h->heap[i].key);

		if (i == 1 || (i & (i + 1)) == 0)
			printf("\n");
	}
	printf("\n");
}

int main(void)
{
	element e1 = { 90 }, e2 = { 89 }, e3 = { 70 }, e4 = { 36 }, e5 = { 75 }, e6 = { 63 }, e7 = { 65 }, e8 = { 21 }, e9 = { 18 }, e10 = { 15 };
	
	HeapType* heap;

	heap = create();
	init(heap);

	insert_max_heap(heap, e1);
	insert_max_heap(heap, e2);
	insert_max_heap(heap, e3);
	insert_max_heap(heap, e4);
	insert_max_heap(heap, e5);
	insert_max_heap(heap, e6);
	insert_max_heap(heap, e7);
	insert_max_heap(heap, e8);
	insert_max_heap(heap, e9);
	insert_max_heap(heap, e10);
	

	free(heap);
	
	printf("--------------------\n| i   : 노드추가   |\n| d   : 노드삭제   |\n| p   : 레벨별 출력|\n| c   : 종료       |\n--------------------\n");
	
	

	while (1) {
		
		
		char menu = "";
		int heapPlus = 0;
		int heapDelete = 0;
		printf("메뉴 입력: ");
		scanf_s("%c", &menu);
		getchar();
		switch (menu)
		{
		case'i':
			printf("추가할 값 입력: ");
			scanf_s("%d", &heapPlus);
			print_heap_level_order(heap);
			insert_max_heap(heap,heapPlus);
			break;
		case'd':
			printf("삭제할 값 입력: ");
			scanf_s("%d", &heapDelete);
			delete_max_heap(heap);
			break;
		case'p':
			printf("트리 레벨별 출력\n");
			for (int num = 1; num <= 4; num++) {
				printf("[%d]\n", num);
			}
			break;
		case'c':
			break;
		default:
			break;
		}
		if (menu == 'c') {
			break;
		}
	}
	return 0;
}
