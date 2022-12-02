#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    while (cur)
    {
        if (cur->val == val)
        {
            if (cur == head)
            {
                head = cur->next;
                free(cur);
                cur = head;

            }
            else
            {
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }
        else
        {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}
int main()
{
    //  自己创建链表
    struct ListNode* newnode1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* newnode4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    //  给链表赋值
    newnode1->val = 7;
    newnode2->val = 7;
    newnode3->val = 7;
    newnode4->val = 7;
    //  调用链表函数
    struct ListNode* head = removeElements(newnode1, 7);
	return 0;
}