#include<stdio.h>
#include<stdlib.h>
int mutex=1,full=0,empty=3,x=0;
int main(){
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while(1){
        printf("\nEnter ur choice:");
        scanf("%d",&n);
        switch(n){
            case 1:if((mutex==1)&&(empty!=0))
            producer();
            else
            printf("Buffer is full!!");
            break;
            case 2:if((mutex==1)&&(full!=0))
            consumer();
            else
            printf("Buffer is empty!!");
            break;
            case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
int wait(int s){
    return(--s);
}
int signal(int s){
    return(++s);
}
void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    x++;
    printf("\nProducer produces the item %d",x);\
    mutex=signal(mutex);
}
void consumer(){
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d",x);
    x--;
    mutex=signal(mutex);
}
//output:
/*1.Producer
2.Consumer
3.Exit
Enter ur choice:1

Producer produces the item 1
Enter ur choice:1

Producer produces the item 2
Enter ur choice:1

Producer produces the item 3
Enter ur choice:1
Buffer is full!!
Enter ur choice:2

Consumer consumes item 3
Enter ur choice:2

Consumer consumes item 2
Enter ur choice:2

Consumer consumes item 1
Enter ur choice:2
Buffer is empty!!
Enter ur choice:3
*/