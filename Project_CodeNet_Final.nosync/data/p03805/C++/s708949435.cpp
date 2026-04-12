#include <iostream>
#include <cstring>
#include<cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#include <ctime>
#include <cstring>
#include <cmath>
#include <stack>
#include <set>
#include <unordered_map>
#define INF 0x3f3f3f3f
#define ll long long
#define rep(i, n) for(ll i=0;i<n;i++)
#define per(i, n) for(int i=n;i>=0;i--)
#define rep2(i, n) for(ll i=1;i<=n;i++)
#define pb(x) push_back(x)
#define clint(x, n) memset(x,n,sizeof(x))
#define mp make_pair
#define fi first
#define se second
#define IO std::ios::sync_with_stdio(false)
#define ull unsigned long long
#define ud long double
#define pii pair<int,int>
using namespace std;
const int maxn = 1e6+5;
const ll inf = 100000000000;
const int mod =998244353;
const int MAX = 123123;
const int N =1005;
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
    return s*w;
}
ll max(ll a,ll b){
    if(a>b) return a;
    return b;
}
ll min(ll a,ll b){
    if(a<b) return a;
    return b;
}
vector<int> a[10];
int used[10];
int ans = 0;
int n;

void bfs(int x,int t){
    if(t==n){
        ans++;
        return;
    }
    for(int i=0;i<a[x].size();i++){
        if(used[a[x][i]]) continue;
        used[a[x][i]]=1;
        bfs(a[x][i],t+1);
        used[a[x][i]]=0;
    }
}
int main(){
    int m;
    cin>>n>>m;
    for(int i = 0; i < m;i++){
        int x,y;
        cin>>x>>y;
        a[x].pb(y);
        a[y].pb(x);
    }
    used[1]=1;
    bfs(1,1);
    cout<<ans<<endl;
    return 0;
}
