#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>

int my_gets(char *buf,int nBuf,FILE *fp){
    int ch;

    while(--nBuf >0){
        ch=getc(fp);
        if(ch==EOF || ch=='\n')
            break;
        *(buf++)=(char)ch;
    }
    *(buf)='\0';

    return nBuf;
}

#define MY_PATH(i,j)  ( ( ((unsigned long long)1) << i*8+j ) | ( ((unsigned long long)1) << j+8+i) )



int SearchPath(int depth,int path[8][8],int N,int M,int i){
    int cnt=0;
    static int Visited[8]={};

    //printf("%d ",i+1);

    if(depth==N-1){
        //puts("*");
        return 1;
    }
    for(int j=0;j<N;j++){
        if(path[i][j] && Visited[j]==0){
            Visited[i]=1;
            cnt += SearchPath(depth+1,path,N, M-1,j);
            Visited[i]=0;
        }
    }
    return cnt;
}


int main(void){
    int N,M;
    int path[8][8]={};
    
    scanf("%d %d%*c",&N,&M);
    for(int i=0;i<M;i++){
        int a,b;
        
        scanf("%d %d%*c",&a,&b);
        path[a-1][b-1]=path[b-1][a-1]=1;
    }
    printf("%d\n",SearchPath(0,path,N,M,0));

    return 0;
}