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
#define MAXN 100005
#define INF 1000000005
#define LINF 1000000000000000005

struct pct{
    long long x,y,id;
} a[100005];

bool comp1(pct a, pct b){
    return a.x<b.x;
}

bool comp2(pct a, pct b){
    return a.y<b.y;
}

int n,v[100005];

long long t;

set <pl> s;

vector <pl> g[100005];

int32_t main(){
    ios_base :: sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i].x >> a[i].y;
        a[i].id=i;
    }
    sort(a+1,a+n+1,comp1);
    for(int i=1;i<n;i++){
        g[a[i].id].pb({a[i+1].id,a[i+1].x-a[i].x});
        g[a[i+1].id].pb({a[i].id,a[i+1].x-a[i].x});
    }
    sort(a+1,a+n+1,comp2);
    for(int i=1;i<n;i++){
        g[a[i].id].pb({a[i+1].id,a[i+1].y-a[i].y});
        g[a[i+1].id].pb({a[i].id,a[i+1].y-a[i].y});
    }
    for(pl i : g[1]){
        s.insert({i.y,i.x});
    }
    v[1]=1;
    while(s.size()){
        pl i=*(s.begin());
        s.erase(s.begin());
        if(v[i.y]) continue;
        v[i.y]=1;
        t+=i.x;
        for(pl j : g[i.y]){
            s.insert({j.y,j.x});
        }
    }
    cout << t;
}

