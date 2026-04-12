#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int inf=1e9;
const ll Inf=1e18;
const int N=1e5+10;
const int mod=0;
int gi() {
    int x=0,o=1;char ch=getchar();
    while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
    if(ch=='-') o=-1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
    return x*o;
}
template<typename T> bool chkmax(T &a,T b) { return a<b?a=b,1:0; };
template<typename T> bool chkmin(T &a,T b) { return a>b?a=b,1:0; };
int add(int a,int b) { return a+b>=mod?a+b-mod:a+b; }
int sub(int a,int b) { return a-b<0?a-b+mod:a-b; }
void inc(int &a,int b) { a=(a+b>=mod?a+b-mod:a+b); }
void dec(int &a,int b) { a=(a-b<0?a-b+mod:a-b); }
vector<int> E[N];
int n,fa[N],cnt[N],du[N],dep[N];
struct cmp {
    bool operator()(int a,int b) { return dep[a]<dep[b]; }
};
priority_queue<int,vector<int>,cmp> q;
set<int> s[N];
void dfs(int u,int ff) {
    fa[u]=ff;
    for(int v:E[u]) if(v!=ff) dep[v]=dep[u]+1,dfs(v,u);
}
void update(int u,int v) {
    s[u].insert(v);
    if(int(s[u].size())==2) puts("First"),exit(0);
}
int main() {
    cin>>n;
    for(int i=1,u,v;i<n;i++) u=gi(),v=gi(),E[u].pb(v),E[v].pb(u),du[u]++,du[v]++;
    if(n==2) return puts("Second"),0;
    if(n&1) return puts("First"),0;
    int rt=0;
    for(int i=1;i<=n;i++) if(du[i]>1) rt=i;
    dfs(rt,0);
    for(int i=1;i<=n;i++) if(du[i]==1) q.push(i),update(fa[i],i);
    while(!q.empty()) {
        int u=q.top();q.pop();
        int p=fa[fa[u]];
        if(fa[p]&&--du[p]==1) update(fa[p],p);
        if(p&&du[p]==(p!=rt)) q.push(p);
    }
    puts("Second");
    return 0;
}
