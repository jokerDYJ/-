#include<stdlib.h>
#include<stdio.h>

#define MAX 100
typedef struct Node {
	struct Node* pre;
	int data;
	struct Node* next;
}Node;

Node* CreatNode(Node* head)
{
    head = (Node*)malloc(sizeof(Node));
    if (head == NULL)
    {
        printf("malloc error!\r\n");
        return NULL;
    }
    head->pre = NULL;
    head->next = NULL;
    head->data = rand() % MAX;
    return head;
}

Node* CreatList(Node* head, int length)
{
    if (length == 1)
    {

        return(head = CreatNode(head));
    }
    else
    {
        head = CreatNode(head);
        Node* list = head;
        for (int i = 1; i < length; i++)
        {
            Node* body = (Node*)malloc(sizeof(Node));
            body->pre = NULL;
            body->next = NULL;
            body->data = rand() % MAX;
            list->next = body;
            body->pre = list;
            list = list->next;
        }

    }
    /*加上以下两句就是双向循环链表*/
    // list->next=head;
    // head->prior=list;
    return head;
}


Node* InsertListHead(Node* head, int add, int data)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("malloc error!\r\n");
        return NULL;
    }
    else
    {
        temp->data = data;
        temp->pre = NULL;
        temp->next = NULL;
    }
    if (add == 1)
    {
        temp->next = head;
        head->pre = temp;
        head = temp;
    }
    else
    {
        Node* body = head;
        for (int i = 1; i < add - 1; i++)
        {
            body = body->next;
        }
        if (body->next == NULL)
        {
            body->next = temp;
            temp->pre = body;
        }
        else
        {
            body->next->pre = temp;
            temp->next = body->next;
            body->next = temp;
            temp->pre = body;
        }
    }
    return head;
}

Node* InsertListEnd(Node* head, int add, int data)
{
    int i = 1;
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->pre = NULL;
    temp->next = NULL;

    Node* body = head;
    while ((body->next) && (i < add + 1))
    {
        body = body->next;
        i++;
    }
    if (body->next == NULL)
    {
        body->next = temp;
        temp->pre = body;
        temp->next = NULL;
    }
    else
    {
        temp->next = body->pre->next;
        temp->pre = body->pre;
        body->next->pre = temp;
        body->pre->next = temp;

    }
    return head;
}

Node* DeleteList(Node* head, int data)
{
    Node* temp = head;
    while (temp)
    {
        if (temp->data == data)
        {
            if (temp->pre == NULL)
            {
                head = temp->next;
                temp->next = NULL;
                free(temp);
                return head;
            }
            else if (temp->next == NULL)
            {
                temp->pre->next = NULL;
                free(temp);
                return head;
            }
            else
            {
                temp->pre->next = temp->next;
                temp->next->pre = temp->pre;
                free(temp);
                return head;
            }
        }
        temp = temp->next;
    }
    printf("Can not find %d!\r\n", data);
    return head;
}

Node* ModifyList(Node* p, int add, int newElem)
{
    Node* temp = p;
    for (int i = 1; i < add; i++)
    {
        temp = temp->next;
    }
    temp->data = newElem;
    return p;
}

int FindList(Node* head, int elem)
{
    Node* temp = head;
    int i = 1;
    while (temp)
    {
        if (temp->data == elem)
        {
            return i;
        }
        i++;
        temp = temp->next;
    }
    return -1;
}

void PrintList(Node* head)
{
    Node* temp = head;
    while (temp)
    {
        if (temp->next == NULL)
        {
            printf("%d\n", temp->data);
        }
        else
        {
            printf("%d->", temp->data);
        }
        temp = temp->next;
    }
}

int main()
{
    Node* head = NULL;
    head = CreatList(head, 5);
    printf("新创建双链表为\t");
    PrintList(head);
    head = InsertListHead(head, 5, 1);
    printf("在表中第 5 的位置插入元素 1\t");
    PrintList(head);
    head = InsertListEnd(head, 3, 7);
    printf("在表中第 3 的位置插入元素 7\t");
    PrintList(head);
    head = DeleteList(head, 7);
    printf("表中删除元素 7\t\t\t");
    PrintList(head);
    printf("元素 1 的位置是\t：%d\n", FindList(head, 1));
    head = ModifyList(head, 3, 6);
    printf("表中第 3 个节点中的数据改为存储6\t");
    PrintList(head);
    return 0;
}
