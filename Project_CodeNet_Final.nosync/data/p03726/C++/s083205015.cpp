#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define pi pair<int,int>
#define pl pair<long long,long long>
#define lg length()
#define pb push_back
ifstream in("file.in");
ofstream out("file.out");
#define MAXN 100005
#define INF 1e9+5
#define int long long
#define LINF 1000000000000000005

int n,x,y,k[100005],r,v[100005],t[100005],ans,f;

vector <int> g[100005];

void DFS(int nod){
    v[nod]=1;
    for(int i : g[nod]){
        if(!v[i]) DFS(i), t[nod]+=(!t[i]);
    }
    if(t[nod]>1) f=1;
}

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> x >> y;
        g[x].pb(y); g[y].pb(x);
    }
    DFS(1);
    if(f || !t[1]) cout << "First";
    else cout << "Second";
}
