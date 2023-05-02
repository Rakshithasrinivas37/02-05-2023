#include <stdio.h>
#include <stdlib.h>

typedef struct single_ll
{
    int data;
    struct single_ll *next;
}sll;

void insert_at_last(int data_arg, sll **head_arg);
void insert_at_first(int data_arg, sll **head_arg);
void delete_at_first(sll **head_arg);
void delete_at_last(sll **head_arg);
void display(sll **head_arg);

int main()
{
    sll *head = NULL;
    int data, option;
    while(1)
    {
        printf("1. Insert at last\n2. Insert at first\n3. Delete at first\n4. Delete at last\n5. Display\n6. Exit\nEnter the option: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1: printf("Enter data: ");
                    scanf("%d", &data);
                    insert_at_last(data, &head);
                    break;
            case 2: printf("Enter data: ");
                    scanf("%d", &data);
                    insert_at_first(data, &head);
                    break;
            case 3: delete_at_first(&head);
                    break;
            case 4: delete_at_last(&head);
                    break;
            case 5: display(&head);
                    break;
            case 6: exit(1);
                    break;
        }
    }
    return 0;
}

void insert_at_last(int data_arg, sll **head_arg)
{
    sll *node = (sll *)malloc(sizeof(sll));
    if(node == NULL)
    {
        printf("Memory not assigned\n");
    }
    else
    {
        node->data = data_arg;
        node->next = NULL;
        if(*head_arg == NULL)
        {
            *head_arg = node;
        }
        else
        {
            sll *temp = *head_arg;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = node;
        }
    }
}

void insert_at_first(int data_arg, sll **head_arg)
{
    sll *node = (sll *)malloc(sizeof(sll));
    if(node == NULL)
    {
        printf("Memory not assigned\n");
    }
    else
    {
        node->data = data_arg;
        node->next = NULL;
        if(*head_arg == NULL)
        {
            *head_arg = node;
        }
        else
        {
            node->next = *head_arg;
            *head_arg = node;
        }
        
    }
}

void delete_at_first(sll **head_arg)
{
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head_arg;
        *head_arg = temp->next;
        free(temp);
    }
}

void delete_at_last(sll **head_arg)
{
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head_arg;
        sll *prev = NULL;
        while(temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next = NULL;
    }
}

void display(sll **head_arg)
{
    if(*head_arg == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        sll *temp = *head_arg;
        printf("Elements are: ");
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
  