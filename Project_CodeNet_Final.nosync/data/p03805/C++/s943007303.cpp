#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int N,M;
int connect[10][10];


int dfs(int v, int bit){
    bit |= (1<<(v-1));
    int count = 0;

    if(bit==(1<<N)-1) return 1;

    for(int i=1;i<=N;i++){
        if(connect[v][i]==1){
            if((bit>>(i-1))&1) continue;
            count += dfs(i, bit);
        }
    }

    return count;
}

int main(void){

    int a,b;

    cin>>N>>M;

    for(int i=0;i<M;i++){
        cin>>a>>b;
        connect[a][b]=1;
        connect[b][a]=1;
    }

    
    cout<<dfs(1,0)<<endl;



    return 0;
}