#include<stdio.h>
int main(void){
    char A[3];
    int a=0;
    int b=0;
    int c=0;
    scanf("%s",A);
    if (A[0]==A[1])
    {a=1;
}
if (A[1]==A[2])
    {b=1;
}
if(A[0]==A[2])
{c=1;
}
    if (a==1&&b==1&&c==1)
    {
       printf("No");
    }else{
        printf("Yes");
    }
}

