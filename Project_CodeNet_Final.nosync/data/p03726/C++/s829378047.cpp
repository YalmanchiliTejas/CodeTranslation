#include<cstdio>
#include<vector>
#include<bitset>
#define N 100000
using namespace std;

vector<int> vecin[N+1];
bitset<N+1> viz;

int dfs(int nod=1){
    viz.set(nod);
    bool ans=false;
    
    for(int i=0;i<vecin[nod].size();i++){
        int now=vecin[nod][i];
        
        if (viz[now]==false){
            int r=dfs(now);
            
            if (r==-1) return -1;
            if (r==1 &&ans==1) return -1;
            ans|=r;
        }
    }
    
    return (ans^1);
}

int main(){
    int n,i;
    
    scanf ("%d",&n);
    
    for(i=1;i<=n;i++){
        int a,b;
        scanf ("%d%d",&a,&b);
        
        vecin[a].push_back(b);
        vecin[b].push_back(a);
    }
    
    int ans=dfs();
    
    if (ans==0) printf ("Second");
    else printf ("First");
    
    return 0;
}
