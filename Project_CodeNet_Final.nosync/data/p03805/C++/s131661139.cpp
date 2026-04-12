#include <bits/stdc++.h>
#include <string>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second　//pairの二つ目の要素

int n,m;
vector<vector<int>> to;
vector<int> vis;
int ans=0;

void dsp(int pos){
    vis[pos]=1;
    for(int npos : to[pos]){
        if(vis[npos]==1)continue;
        vis[npos]=1;
        dsp(npos);
        vis[npos]=0;
    }
    bool judge=true;
    rep(i,n){
        judge=judge && (vis[i]==1);
    }
    if(judge) ans++;
}

int main(){
    cin>>n>>m;
    to.resize(n);
    vis.resize(n);
    rep(i,m){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    dsp(0);
    cout<<ans<<endl;
    return 0;
}