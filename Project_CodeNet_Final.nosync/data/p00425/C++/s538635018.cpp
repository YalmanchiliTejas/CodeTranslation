
#include<string.h>
#include<stdio.h>

int main(void){
    int N=5,U=1,W=4,E=3,D=6,S=2,sub=0;
    int n,i;
    int count=1;
    for(;;){
        N=5,U=1,W=4,E=3,D=6,S=2,sub=0,count=1;
        scanf("%d",&n);
        if(n==0)break;
        char a[10];//[10000]={0};
        for(i=0;i<n;i++){
            scanf("%s",a);
            if(strcmp(a,"North")==0)sub=N,N=U,U=S,S=D,D=sub,count+=U;
            else if(strcmp(a,"South")==0)sub=D,D=S,S=U,U=N,N=sub,count+=U;
            else if(strcmp(a,"East")==0)sub=E,E=U,U=W,W=D,D=sub,count+=U;
            else if(strcmp(a,"West")==0)sub=D,D=W,W=U,U=E,E=sub,count+=U;
            else if(strcmp(a,"Right")==0)sub=E,E=N,N=W,W=S,S=sub,count+=U;
            else if(strcmp(a,"Left")==0)sub=S,S=W,W=N,N=E,E=sub,count+=U;
            }
        printf("%d\n",count);
    }



	return 0;
}