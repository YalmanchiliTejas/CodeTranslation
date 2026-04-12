#include <stdio.h>
int seen[8]={};

int dfs(int N,int G[8][8],int next){
    int flag = 1;
    for(int i = 0; i < N; i++){
        if(seen[i]==0){
            flag = 0;
            break;
        }
    }
    
    if(flag == 1){
        return 1;
    }
    
    int ret = 0;
    for(int i = 0; i < N; i++){
        if(seen[i])
            continue;
        if(G[next][i]==0)
            continue;
        
        seen[i]=1;
        ret += dfs(N,G,i);
        seen[i]=0;
    }
    
    return ret;
}

int main(void){
    // Your code here!
    int N,M;
    int G[8][8] = {};
    scanf("%d%d",&N,&M);
    
    for(int i = 0; i < M;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a-1][b-1]=1;
        G[b-1][a-1]=1;
    }
    
    seen[0]=1;
    int ret = dfs(N,G,0);
    
    printf("%d\n",ret);
}
