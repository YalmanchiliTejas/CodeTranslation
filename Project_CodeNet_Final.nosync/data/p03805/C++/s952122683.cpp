#include<iostream>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<algorithm> 
using namespace std;
 
# define p(s) std::cout << s << endl;
# define printIf(j,s1,s2) cout << (j ? s1 : s2) << endl;
# define YES(j) cout << (j ? "YES" : "NO") << endl;
# define Yes(j) std::cout << (j ? "Yes" : "No") << endl;

const int limit=30;

int a[limit],b[limit];

int graph[limit][limit];
bool isVisited[limit];

bool isAllVisited(int n){
    bool ans=true;
    for(int i=0;i<n;i++){
        if(!isVisited[i]) ans = false;
    }
    return ans;
}

int dfs(int v,int depth,int n){
    if(depth==n) {
        if(isAllVisited(n)) return 1;
        else return 0;
    } 
    int ret=0;
    for(int v2=0;v2<n;v2++){
        if(isVisited[v2]) continue;
        if(!graph[v][v2]) continue;
        isVisited[v2]=true;
        ret += dfs(v2,depth+1,n);
        isVisited[v2]=false;
    } 
    return ret;
}

int main()
{
    int n,m;cin >> n >> m;

    for(int i=0;i<m;i++){
        cin >> a[i] >> b[i];
        a[i]--;b[i]--;
        graph[a[i]][b[i]]=graph[b[i]][a[i]]=true;
    }
    isVisited[0]=true;
    p(dfs(0,1,n))
}