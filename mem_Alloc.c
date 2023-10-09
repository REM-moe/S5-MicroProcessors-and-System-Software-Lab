#include<stdio.h>
#include<stdlib.h>
void firstfit(int b,int bs[],int p,int ps[])
{
    int allocation[50],i,j;
    for(i=0;i<b;i++)
    {
        allocation[i]=-1;
    } 
    for(i=0;i<p;i++)
    {
        for(j=0;j<b;j++)
        {
            if(allocation[j]==-1&&bs[j]>=ps[i])
            {
                allocation[j]=i;
                break;
            }
        }
    } 
    printf("\nBlock no \t size \t pno \t size \n");
    for(i=0;i<b;i++)
    {
        printf("\n%d\t\t%d",i+1,bs[i]);
        if(allocation[i]!=-1)
        {
            printf("\t%d\t  %d",allocation[i]+1,ps[allocation[i]]);
        }
        else
        {
            printf("\tNA");
        }
    }
}

void bestfit(int b,int bs[],int p,int ps[])
{
    int allocation[50],i,j,bi;
    for(i=0;i<b;i++)
    {
        allocation[i]=-1;
    } 
    for(i=0;i<p;i++)
    {
        bi=-1;
        for(j=0;j<b;j++)
        {
            if(allocation[j]==-1&&bs[j]>=ps[i])
            {
                if(bi==-1)
                {
                    bi=j;
                }
                else if(bs[bi]>bs[j])
                {
                    bi=j;
                }
            }
        } 
        if(bi!=-1)
        {
            allocation[bi]=i;  
        }  
    }
    printf("\nBlock no \t size \t pno \t size \n");
    for(i=0;i<b;i++)
    {
        printf("\n%d\t\t%d",i+1,bs[i]);
        if(allocation[i]!=-1)
        {
            printf("\t%d\t  %d",allocation[i]+1,ps[allocation[i]]);
        }
        else
        {
            printf("\tNA");
        }
    }
}

void worstfit(int b,int bs[],int p,int ps[])
{
    int allocation[50],i,j,wi;
    for(i=0;i<b;i++)
    {
        allocation[i]=-1;
    } 
    for(i=0;i<p;i++)
    {
        wi=-1;
        for(j=0;j<b;j++)
        {
            if(allocation[j]==-1&&bs[j]>=ps[i])
            {
                if(wi==-1)
                {
                    wi=j;
                }
                else if(bs[wi]<bs[j])
                {
                    wi=j;
                }
            }
        } 
        if(wi!=-1)
        {
            allocation[wi]=i;  
        }  
    }
    printf("\nBlock no \t size \t pno \t size \n");
    for(i=0;i<b;i++)
    {
        printf("\n%d\t\t%d",i+1,bs[i]);
        if(allocation[i]!=-1)
        {
            printf("\t%d\t  %d",allocation[i]+1,ps[allocation[i]]);
        }
        else
        {
            printf("\tNA");
        }
    }
}
void main()
{
    int bno,bsize[50],i,ch,pno,psize[50];
    printf("Enter no of blocks\n");
    scanf("%d",&bno);
    printf("Enter size of each block\n");
    for(i=0;i<bno;i++)
    {
        printf("block %d:",i+1);
        scanf("%d",&bsize[i]);
    }
     printf("Enter no of process\n");
    scanf("%d",&pno);
    printf("Enter size of each process\n");
    for(i=0;i<pno;i++)
    {
        printf("process %d:",i+1);
        scanf("%d",&psize[i]);
    }
    while(1)
    {
        printf("\nEnter your choice \n1.First Fit \n2.Best Fit \n3.Worst Fit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:firstfit(bno,bsize,pno,psize);
            break;
            case 2:bestfit(bno,bsize,pno,psize);
            break;
            case 3:worstfit(bno,bsize,pno,psize);
            break;
            default:exit(0);
            break;
        }
    }
}
