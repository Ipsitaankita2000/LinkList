#include<stdio.h>  
#include<stdlib.h>  
struct node   
{  
    int data;  
    struct node *next;   
};  
struct node *start;  
               /*fuction declaration of all the operations*/
void create();
void insert_begin();   
void insert_last();  
void insert_locc();  
void delete_begin();  
void delete_last();  
void delete_locc(); 
void deletedata(); 
void print();  
void main ()  
{  
    int choi;  
    while(1)   
    {    
          
        printf("\n 1 Create \n 2.Insert in the begining\n3.Insert at last\n4.Insert at any specified position\n5.Delete from Beginning\n6.Delete from last\n7.Delete node after specified location\n8.Show\n9.Exit\n 10 delete data");           
        printf("\nEnter the operation to be performed\n");  
		scanf("%d",&choi);  
        switch(choi ) 
        { 
			case 1:
				create(); 
				break;     /*function calls of all the operations */
            case 2:  
            insert_begin();       
            break;  
            case 3:  
            insert_last();         
            break;  
            case 4:  
            insert_locc();       
            break;  
            case 5:  
            delete_begin();       
            break;  
            case 6:  
            delete_last();        
            break;  
            case 7:  
            delete_locc();           
            break;  
            case 8:  
            print();        
            break; 
			case 10:
			deletedata(); 
			break;
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Enter valid option");  
        }  
    }  
}           /*function definition*/

void create()
{
	 struct node *p,*temp;
	 int value;
	p=(struct node *) malloc(sizeof(struct node));  
    if(p == NULL)  
    {  
        printf("\nOVERFLOW");  
        exit(0);
    }  
    
    printf("\nEnter  Data:");    
    scanf("%d",&p->data); 
     
        p->next= NULL;  
        if(start== NULL) 
        {
        	start=p;
        	
		}
		   
		else
		{
			temp=start;
			while(temp->next != NULL)
			{
				temp=temp->next;
				
			}
			temp->next=p;
		}
}
	 
	 
	
	






void insert_begin()                  //to insert the node at the beginnning of linked list

{  
    struct node *p;  
    int value;  
    p=(struct node *) malloc(sizeof(struct node ));  
    if(p==NULL)  
    {  
        printf("\n out of memory space..."); 
		return;
    }  
    else  
    {  
        printf("\nEnter data :");    
        scanf("%d",&value);    
        p->data=value;  
        p->next=start;  
        start=p;  
    }  
}  
void insert_last()                //to insert the node at the last of linked list
{  
    struct node *p,*temp;  
    int value;     
    p=(struct node*)malloc(sizeof(struct node));      
    if(p==NULL)  
    {  
        printf("\nOVERFLOW");     
    }  
    else  
    {  
        printf("\nEnter Data:");  
        scanf("%d",&value);  
        p->data=value;  
        if(start==NULL)  
        {  
            p->next=NULL;  
            start=p;  
        }  
        else  
        {  
            temp=start;  
            while(temp->next!=NULL)  
            {  
                temp=temp->next;  
            }  
            temp->next=p;  
            p->next=NULL;  
        }  
    }  
}  
void insert_locc()               //to insert the node at the specified location of linked list
{  
    int i,loc,value;   
    struct node *p, *temp;  
    p=(struct node *)malloc(sizeof(struct node));  
    if(p==NULL)  
    {  
        printf("\nOVERFLOW");  
    }  
    else  
    {  
        printf("\nEnter element Data:");  
        scanf("%d",&value);  
        p->data=value;  
        printf("\nEnter the location in  which you want to insert ");  
        scanf("\n%d",&loc);  
        temp=start;  
        for(i=0;i<loc-1;i++)  
        {  
            temp=temp->next;  
            if(temp==NULL)  
            {  
                printf("\ncan't insert\n");  
                return;  
            }  
        }  
        p->next=temp->next;   
        temp->next=p; 
    }  
}  
void delete_begin()          //to delete the node present in the beginning of the linked list
{  
    struct node *p;  
    if(start==NULL)  
    {  
        printf("\nList is empty\n");  
    }  
    else   
    {  
        p=start;  
        start=p->next;  
        free(p);  
    }  
}  
void delete_last()          //to delete the node present in the last of the linked list
{  
    struct node *p,*p1;  
    if(start==NULL)  
    {  
        printf("\n list is empty");  
    }  
    else if(start->next==NULL)  
    {  
        start=NULL;  
        free(start);  
        printf("\n Only node of the list deleted ...\n");  
    }  
    else  
    {  
        p=start;   
        while(p->next!=NULL)  
        {  
            p1=p;  
            p=p->next;  
        }  
        p1->next=NULL;  
        free(p);  
    }     
}  
void delete_locc()    //to delete the node present at the specified of the linked list
{  
    struct node *p,*p1;  
    int loc,i;    
    printf("\n Enter the location in  which you want to perform deletion \n");  
    scanf("%d",&loc);  
    p=start;  
    for(i=0;i<loc;i++)  
    {  
        p1=p;       
        p=p->next;  
           
        if(p==NULL)  
        {  
            printf("\nCan't delete");  
            return;  
        }  
    }
}












void deletedata()
{
	struct node *p=start;
	struct node *p1=start->next;
	
	
	int deldata;
	int count;
	count=0;
	int i;
	printf("\n Enter the data which you want to delete \n");  
    scanf("%d",&deldata);
     while (p1->data != deldata && p1->next != NULL)
	 {
	 	  p = p->next;
		  p1 = p1->next;
       
	 	
	   }  
	   if(p1->data == deldata)
		{
        	p->next = p1->next;
        	free(p1);
    	}
        
}
 
void print()    //to print the values in the linked list
{  
    struct node *p;  
    p=start;   
    if(p==NULL)  
    {  
        printf("Nothing to print");  
    }  
    else  
    {  
        printf("\nprinting values:");   
        while (p!=NULL)  
        {  
            printf("%d -->",p->data);  
            p=p->next;  
        }  
    }  
}    
