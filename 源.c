#include <stdio.h>
#include <stdlib.h>
typedef struct List
{
	int  data;
	struct List* next;
}list, * p_list;

void creat_list(list** p)
{						 
	int item;
	list* temp;
	list* target;
	printf("����ڵ��ֵ������0����\n");
	while (1)
	{
		scanf("%d", &item);
		if (item == 0)break;

		if (*p == NULL)   
		{

			*p = (list*)malloc(sizeof(list));
			if (!*p)exit(0);
			(*p)->data = item;
			(*p)->next = *p;
		}
		else		
		{
			for (target = *p; target->next != *p; target = target->next);

			temp = (list*)malloc(sizeof(list));
			if (!temp)exit(0);
			temp->data = item;
			temp->next = *p;  
			target->next = temp;
		}
	}
}
void insert(list** pNode, int place, int num)  
{
	list* temp, * target;
	int i;
	if (place == 1)				
	{						
		temp = (list*)malloc(sizeof(list));
		if (!temp)exit(0);
		temp->data = num;
		for (target = *pNode; target->next != *pNode; target = target->next);

		temp->next = *pNode;
		target->next = temp;
		*pNode = temp;
	}

	else								
	{				
		for (i = 1, target = *pNode; target->next != *pNode && i != place - 1; target = target->next, i++);
		temp = (list*)malloc(sizeof(list));
		temp->data = num;

		temp->next = target->next;
		target->next = temp;
	}

}

void Delete(list** pNode, int place)  
{
	list* temp, * target;
	int i;
	temp = *pNode;
	if (temp == NULL)				
	{
		printf("����һ����ָ�� �޷�ɾ��\n");
		return;
	}
	if (place == 1)		
	{				
		for (target = *pNode; target->next != *pNode; target = target->next);
		temp = *pNode;

		*pNode = (*pNode)->next;
		target->next = *pNode;
		free(temp);
	}
	else
	{		
		for (i = 1, target = *pNode; target->next != *pNode && i != place - 1; target = target->next, i++); 
		if (target->next == *pNode)		
		{
			for (target = *pNode; target->next->next != *pNode; target = target->next);
			temp = target->next;												
			target->next = *pNode;
			printf("����̫��ɾ��β��\n");
			free(temp);
		}
		else
		{
			temp = target->next;
			target->next = temp->next;
			free(temp);
		}
	}
}

int findval(list* pNode, int val) 
{
	int i = 1;
	list* node;
	node = pNode;
	while (node->data != val && node->next != pNode)
	{
		i++;
		node = node->next;
	}
	if (node->next == pNode && node->data != val)
	{
		return -1;
	}
	return i;
}



void show(list* p)
{
	list* temp;
	temp = p;
	do
	{
		printf("%5d", temp->data);
		temp = temp->next;
	} while (temp != p);

	printf("\n");
}
int main()
{
	list* head = NULL;
	//list *val;
	int place, num;
	creat_list(&head);
	printf("ԭʼ������");
	show(head);

	printf("����Ҫɾ����λ�ã�");
	scanf("%d", &place);
	Delete(&head, place);
	show(head);

	printf("����Ҫ�����λ�ú������ÿո������");
	scanf("%d %d", &place, &num);
	insert(&head, place, num);
	show(head);

	printf("����������ҵ�ֵ:");
	scanf("%d", &num);
	place = findval(head, num);
	if (place != -1)printf("�ҵ���ֵ��λ����place=%d\n", place);
	else printf("û�ҵ�ֵ\n");

	return 0;
}