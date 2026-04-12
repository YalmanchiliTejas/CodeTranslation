#include <bits/stdc++.h>
using namespace std;
using Int = long long;
typedef pair<int,int> P; typedef priority_queue<int> Pr; typedef vector<int> V; typedef vector<P> Vp; typedef map<int,int> MP;
const int mod = 1000000007; const Int INF = 1145141919810893931;
#define END {cout<<ans<<'\n'; return 0;}
template<class T> inline bool cmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool cmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

Int n,m,ans,l[51],p[51];
void dfs(int d,Int x){
    if(d<0||x<=0)return;
    if(x<=d)return;
    if(x>=l[d]-d){ans+=p[d]; return;}
    if(x>=l[d-1]+2){ans+=p[d-1]+1; dfs(d-1,x-l[d-1]-2); return;}
    if(x>=l[d-1]+2-d){ans+=p[d-1]; return;}
    dfs(d-1,x-1);
    return;
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);

    cin>>n>>m; l[0]=1,p[0]=1;
    for (int i = 0; i < n; i++){
        l[i+1]=l[i]*2+3,p[i+1]=p[i]*2+1;
    }
    dfs(n,m);
    cout<<ans<<'\n';
}