#include<bits/stdc++.h>
using namespace std;


struct hashNode
{
 int value;
 struct hashNode *next;

}table[10],*current,*temp,*previ;



void initial()
{
    for (int i = 0; i < 10; i++)
    {

        table[i].value =-1;
        table[i].next=NULL;
    }



}


void insertion( int k)
{
    int location=k%10;

    if(table[location].value ==-1)
    {
        table[location].value=k;
    }
    else
    {
        if(table[location].next==NULL){
            
            current=(struct hashNode*)malloc(sizeof(struct hashNode));
            table[location].next=current;
            current->value=k;
            current->next=NULL;
           
        }
       else{
            temp=table[location].next;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
             current=(struct hashNode*)malloc(sizeof(struct hashNode));
             temp->next=current;
             current->value=k;
             current->next=NULL;
            //traverse, create node
        }
       
    }


}


void printtable()
{
 for (int i = 0; i < 10; i++)
    {

        printf("%d",table[i].value);

        if(table[i].next==NULL)
        {
             printf("\n");
        }
        else{
            temp=table[i].next;
            while(temp!=NULL)
            {
                printf("-->%d",temp->value);
                temp=temp->next;
                
            }
            printf("\n");
             
        
        }
       

    }

}


void search(int s)
{
int location=s%10;
int index=0;
bool alert;
if(table[location].value==s)
{
    printf(">>found:%d location:[%d][%d]",table[location].value,location,index);
    alert=1;
}
else{
index=1;
temp=table[location].next;
 while(temp!=NULL){
    if(temp->value==s){
                    
        printf("\n>>found:%d location:[%d][%d]\n",temp->value,location,index);
        alert=1;
        break;            
    }
    temp=temp->next;
    index++;
                
}
    if(alert==0)
    {
     printf("\n>>Not found\n");
    }

}

}


void deleteElement(int s){

int location=s%10;
int index=0;
bool alert;
if(table[location].value==s)
{
    
    table[location].value=-1;
    alert=1;
}
else{
index=1;
temp=table[location].next;
previ=table[location].next;//can not point only head
 while(temp!=NULL){
    if(temp->value==s){
           if(index==1)
           {
           table[location].next=temp->next;
          

           }  
           else{

               previ->next=temp->next;

           }       
        alert=1;
        break; 
        

                  
    }
    previ=temp;
    temp=temp->next;
    index++;
                
}
  
}

  if(alert==0)
    {
     printf("\n>>Not found!!\n");
    }
    else{
        printf("\nDeleted!\n");
    }

}


int main()
{
    int input,in=0;
      initial();
      

    while(1){
        printf("\n______________________");
        printf("\n\n>>1 for Insert\n>>2 for view\n>>3 for searching\n>>4 for delete\n>>0 for exit\ninput:_");
        scanf("%d",&in);
        if(in==1){
         printf("Enter:_");   
         scanf("%d",&input);
         insertion(input);
         printf("______________________");

        }
        else if(in==2){
            printf("\n>>Full hash table:\n");
             printtable();
             printf("______________________");

        }
        else if(in==3){
            printf("\nEnter For search:_");   
            scanf("%d",&input);
            search(input);
        }
        else if(in==4){
            printf("\nEnter For Delet:_");   
            scanf("%d",&input);
            deleteElement(input);
        }
        else if(in==0){
            printf("\n>>Done\n");
            break;
        }
        else{
            printf("\n>>Wrong Input\n");
            
        }
        
   
    

    }
    

                 



}