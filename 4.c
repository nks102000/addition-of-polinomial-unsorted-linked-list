//1905622 - NITISH KUMAR SONTHALIA
//Polynomial
#include<stdio.h>
#include <stdlib.h>



struct node
{
    int coff;
    int exp;
    struct node *next;
};

void creat_poly(struct node ** ,int c,int e);
void display_poly(struct node ** );
void add_poly(struct node **,struct node **,struct node **);
void adjust_ploy(struct node **);

int main(){
    struct node *start = NULL;

    struct node *start1 = NULL;

    struct node *start2 = NULL;

    int t;

    int f=1;

    while(f){
    printf("\n MENU ");
    printf("\n 1. Enter An Element In Poly 1 ");
    printf("\n 2. Enter An Element In Poly 2 ");
    printf("\n 3. Display Poly ");
    printf("\n 4. ADD Poly ");
    printf("\n 5. Exit ");
    scanf("%d",&t);
    int c,e;
    
    switch (t)
    {

    case 1:
        printf("\n Enter The Element Coff To Be Entered in Poly 1: ");
        scanf("%d",&c);
        printf("\n Enter The Element Exponent To Be Entered in Poly 1: ");
        scanf("%d",&e);
        creat_poly(&start1,c,e);
        break;
    case 2:
        printf("\n Enter The Element Coff To Be Entered in Poly 2: ");
        scanf("%d",&c);
        printf("\n Enter The Element Exponent To Be Entered in Poly 3: ");
        scanf("%d",&e);
        creat_poly(&start2,c,e);
        break;
    case 3:
        printf("\n Enter The List You Want To Print: ");
        scanf("%d",&e);
        if(e==1)
        display_poly(&start1);
        else if(e==2)
        display_poly(&start2);
        else if(e==3)
        display_poly(&start);
        else
        printf("\n Enter the Correct list number ");
        break;
    case 4:
        add_poly(&start1,&start2,&start);
        adjust_ploy(&start);
        break;
    case 5:
        f=0;
        break;

    default:
        break;
    }
    }
}

void creat_poly(struct node **st ,int c,int e){
    
    struct node *temp;

    struct node *new1 = (struct node *)malloc(sizeof(struct node ));

    new1->coff=c;
    new1->exp=e;

    new1->next=NULL;

    if(*st==NULL){
        *st=new1;
    }
    else{
        temp=*st;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = new1;
    }
    
}



void display_poly(struct node **st){

    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }

    struct node*temp=*st;
        printf("Elements in LIST are:");

    while(temp!=NULL){
        printf("%dx^%d ",temp->coff,temp->exp);
        temp=temp->next;
        if(temp!=NULL)
            printf("+");
    }
}

void add_poly(struct node **st1,struct node **st2,struct node **st3){
    struct node *t1,*t2;
    t1=*st1;
    t2=*st2;
    while(t1!=NULL&&t2!=NULL){
        if(t1->exp>t2->exp){
            creat_poly(st3,t1->coff,t1->exp);
            t1=t1->next;
        }
        else if(t1->exp<t2->exp){
            creat_poly(st3,t2->coff,t2->exp);
            t2=t2->next;
        }
        else{
            if(t1->coff+t2->coff){
                creat_poly(st3,t1->coff,t1->exp);
                t2=t2->next;
                t1=t1->next;
            }
        }
    }
    while(t1!=NULL){
        creat_poly(st3,t1->coff,t1->exp);
        t1=t1->next;
    }
    while(t2!=NULL){
        creat_poly(st3,t2->coff,t2->exp);
        t2=t2->next;
    }
    display_poly(st3);
}

void adjust_ploy(struct node **st){
    struct node *st1,*st2,*prev;
    for(st1=*st;st!=NULL;st1=st1->next){
        prev=st1;
        st2=st1->next;
        while(st2!=NULL){
            if(st1->exp!=st2->exp){
                prev=st2;
                st2=st2->next;
            }
            else
            {
                st1->coff = st1->coff + st2->coff;
                prev->next = st2->next;
                st2=st2->next;
            }
        }
    }
}