#include <bits/stdc++.h>
using namespace std;
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define eror(x) cout<<#x<<'='<<(x)<<endl;
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define All(x) x.begin(),x.end()
#define gett(x) scanf("%d",&x);
#define Add(x,y) x=(x+y)%p
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1e5+9;

int n,u,v,ans,mark[N],sub[N];
vector<int> g[N];

void dfs(int x,int par){
    sub[x]=1;
    f(i,0,g[x].size())
        if(g[x][i]!=par)
            dfs(g[x][i],x),sub[x]+=sub[g[x][i]];
    if(sub[x]&1) mark[x]++,mark[par]++;
}

int main(){
    cin>>n;
    f(i,1,n){
        Gett(u,v);
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(1,0);
    ans=1;
    if(n&1) ans=0;
    f(i,1,n+1)
        if(mark[i]!=1)
            ans=0;
    if(ans) cout<<"Second";
    else cout<<"First";
}