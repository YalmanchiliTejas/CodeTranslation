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
    int cnt1=0,cnt0=0;
    for(int i : g[nod]){
        if(!v[i]){
            DFS(i);
            if(!t[i]) cnt0++;
            else cnt1++;
        }
    }
    if(cnt1 && !cnt0) t[nod]=0;
    else if(cnt0==1) t[nod]=1;
    else if(cnt0>1) f=1;
}

int32_t main(){
    ios_base :: sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<n;i++){
        cin >> x >> y;
        g[x].pb(y); g[y].pb(x);
        k[x]++; k[y]++;
    }
    if(n==2){
        cout << "Second";
        return 0;
    }
    r=1;
    while(k[r]==1) r++;
    DFS(r);
    if(f || !t[r]) cout << "First";
    else cout << "Second";
}
