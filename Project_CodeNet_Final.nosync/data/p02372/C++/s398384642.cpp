#include <stdio.h>
#include <vector>
#include <utility>
#include <bitset>
using namespace std;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
const int N=1e4+10;
vector<pi> graph[N];
bitset<N> went;
int dep[N][2],top,rad;
int max(int a,int b){return a>b?a:b;}
void dfs(int now,bool f){
    if(dep[now][f]>top){
        top=dep[now][f];
        rad=now;
    }
    went[now]=true;
    for(pi i:graph[now])if(!went[i.F]){
        dep[i.F][f]=dep[now][f]+i.S;
        dfs(i.F,f);
    }
    return ;
}
int main(){
    int n,l,r,w;
    scanf("%d",&n);
    for(int i=0;i<n;i++)dep[i][0]=dep[i][1]=0;
    went.reset();
    for(int i=1;i<n;i++){
        scanf("%d%d%d",&l,&r,&w);
        graph[l].PB({r,w});
        graph[r].PB({l,w});
    }
    went.reset();
    top=rad=0;
    dep[0][false]=0;
    dfs(0,false);
    went.reset();
    top=0;
    dep[rad][false]=0;
    dfs(rad,false);
    went.reset();
    dep[rad][true]=0;
    dfs(rad,true);
    for(int i=0;i<n;i++)printf("%d\n",max(dep[i][0],dep[i][1]));
}
