#include "ll.h"

int main ()
{

    unsigned int input = 0;
    head_t head = {0};
    head_t even = {0};
    head_t odd = {0};

    RESET_HEAD(&head);
    RESET_HEAD(&even);
    RESET_HEAD(&odd);

    while (1) {
        printf("Please select following option\n"
                "1. insert a node\n"
                "2. delete a node\n"
                "3. show linked list\n"
                "4. seperate out even and odd node\n"
                "5. join back even and odd node\n"
                "x. any key to exit\n");
        scanf("%d", &input);

        switch(input) {
            case 1:
                insert_node(&head);
                break;
            case 2:
                delete_node(&head);
                break;
            case 3:
                show_list(&head);
                break;
            case 4:
                seprate_even_odd(&head, &even, &odd);
                break;
            case 5:
                join_even_odd(&head, &even, &odd);
                break;
            default:
                printf("Bye bye\n");
                goto end;
        }
        input = 0;
    }
end:
    return 0;
}
