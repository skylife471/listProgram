#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}
ListNode* insert(ListNode* head, ListNode* prev, element value)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = prev->link;
    prev->link = p;
    return head;
}
ListNode* delete_first(ListNode* head)
{
    if (head == NULL)
        return NULL;
    ListNode* removed;
    removed = head;
    head = removed->link;
    free(removed);
    return head;
}

ListNode* deleteList(ListNode* head, ListNode* prev)
{
    ListNode* removed;
    removed = prev->link;
    prev->link = removed->link;
    free(removed);
    return head;
}
void print_list(ListNode* head)
{
    for (ListNode* p = head; p != NULL; p = p->link)
        printf("%d->", p->data);

}
int main(void)
{
    ListNode* head = NULL;
    for (;;)
    {
        int input;
        printf("Menu\n");
        printf("(1) Insert\n");
        printf("(2) Delete\n");
        printf("(3) Print\n");
        printf("(0) Exit\n");
        printf("Enter the menu:");
        scanf("%d", &input);
        switch (input)
        {

        case 1:
            int num, pos;
            printf("Enter the number and position: ");
            scanf("%d %d", &num, &pos);
            if (pos == 0) {
                head = insert_first(head, num);
                printf("\n");
                printf("move along the link: 0\n");
            }
            else if (pos == 1) {
                if (head == NULL) {
                    head = insert_first(head, num);
                    printf("List is empty. Insert at position 0..\n");
                    printf("\n");
                    printf("move along the link : 0\n");
                }
                else {
                    head = insert(head, head, num);
                    printf("\n");
                    printf("move along the link : 1\n");
                }
            }
            else if (pos >= 2) {
                ListNode* prev = head;
                int i = 0;
                while (prev->link != NULL && i < pos - 1) {
                    prev = prev->link;
                    i++;
                }
                if (prev->link == NULL) {
                    prev->link = insert_first(prev->link, num);

                    if (pos - i > 1)
                    {
                        
                        printf("The last index is %d. Insert at position %d..\n", i, i + 1);
                        printf("\n");
                        printf("move along the link : %d\n", i + 1);
                        break;
                    }
                    printf("\n");
                    printf("move along the link : %d\n", pos);
                }
                
                break;
            }
            break;
                
        case 2:
            int input1;
            printf("Enter the position to delete: ");
            scanf("%d", &input1);

            if (input1 == 0) {
                if (head == NULL) {
                    
                    printf("List is empty\n");
                }
                else {
                    head = delete_first(head);
                    printf("\n");
                    printf("move along the link : %d\n", input1);
                }
            }
            else if (input1 >= 1) {
                ListNode* prev = head;
                int i = 0;

                while (prev->link != NULL && i < input1 - 1) {
                    prev = prev->link;
                    i++;
                }

                if (prev->link == NULL) {
                    printf("Invalid position\n");
                }
                else {
                    head = deleteList(head, prev);
                    printf("\n");
                    printf("move along the link : %d\n", input1);
                }

            }
            break;

        case 3:
            print_list(head);
            printf("\n");
            break;
        case 0:
            exit(1);
            break;
        default:
            printf("Invalid Menu. PLease select again");
            break;
            }

            printf("\n");
        }
        
    
    return 0;
}