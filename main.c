#include "dclist.h"

int main() {
    DCList mydclist;
    DCListInit(&mydclist);

    int select = 1, item, key;
    DCListNode *p;

    while (select) {
        printf("***************************************\n");
        printf("*  [1]push_back        [2]push_front  *\n");
        printf("*  [3]show_list        [0]quit_system *\n");
        printf("*  [4]pop_back         [5]pop_front   *\n");
        printf("*  [6]insert_pos       [7]insert_val  *\n");
        printf("*  [8]delete_pos       [9]delete_val  *\n");
        printf("*  [10]find            [11]reverse    *\n");
        printf("*  [12]sort            [13]length     *\n");
        printf("*  [14]capacity        [15]clear      *\n");
        printf("***************************************\n");
        printf("请输入你的选择:>");
        scanf("%d", &select);
        switch (select) {
            case 0:
                break;
            case 1:
                printf("请输入要插入的元素的值:>");
                while (scanf("%d", &item), item != -1) {
                    DCListPushBack(mydclist, item);
                }
                break;
            case 2:
                printf("请输入要插入的元素的值:>");
                while (scanf("%d", &item), item != -1) {
                    DCListPushFront(mydclist, item);
                }
                break;
            case 3:
                DCListShow(mydclist);
                break;
            case 4:
                DCListPopBack(mydclist);
                break;
            case 5:
                DCListPopFront(mydclist);
                break;
            case 6:
                break;
            case 7:
                printf("请输入要插入元素的值:>");
                scanf("%d", &item);
                DCListInsertByVal(mydclist, item);
                break;
            case 8:
                break;
            case 9:
                printf("请输入要删除的元素的:>");
                scanf("%d", &key);
                DCListDeleteByVal(mydclist, key);
                break;
            case 10:
                printf("请输入要查找的元素的值:>");
                scanf("%d", &key);
                p = DCListFind(mydclist, key);
                if (p == NULL)
                    printf("该元素不存在\n");
                else
                    printf("data = %d\n", p->data);
                break;
            case 11:
                DCListReverse(mydclist);
                break;
            case 12:
                DCListSort(mydclist);
                break;
            case 13:
                printf("%lu\n", DCListLength(mydclist));
                break;
            case 14:
                break;
            case 15:
                DCListClear(mydclist);
                break;
            default:
                break;
        }
    }
    DCListDestroy(&mydclist);

    return 0;
}
