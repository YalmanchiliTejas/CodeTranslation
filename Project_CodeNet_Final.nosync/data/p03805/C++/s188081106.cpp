#include <iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include <queue>
typedef long long int ll;
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define EREP(i,n) for (int i=1;i<=(n);i++)
const ll MOD = 1000000007;

int N,M,K,a,b,ans=0,temp=0;
bool node[10][10]={0};
bool vis[10]={0};
int DFS(int p,bool *flag,int temp);
int main(){
    scanf("%d %d",&N,&M);
    EREP(i,M){
        scanf("%d %d",&a,&b);
        node[a][b]=node[b][a]=true;
    }
    vis[1]=vis[0]=true;
    printf("%d",DFS(1,vis,ans));
}

int DFS(int p,bool *flag,int temp){
    // cout<<p<<":"<<temp<<endl;
    int count=0;
    EREP(i,N){
        if(flag[i])count++;
// cout<<i<<":"<<count<<endl;
        if(count==N){
// cout<<"P="<<p<<" ans="<<ans<<" count "<<count<<endl;
            temp++;
            return temp;
        }
    }
    EREP(i,N){
//cout<<p<<" p:i "<<i<<" i:temp "<<temp<<endl;
        if(node[p][i]&&!flag[i]){
            flag[i]=true;
            temp=DFS(i,flag,temp);
            flag[i]=false;
        }
    }
    return temp;
}
