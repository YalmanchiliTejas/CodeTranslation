#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

bool g[10][10];//隣接行列

int main(){
    ll n,m;cin >>n>>m;
    for (int i = 0; i < m; ++i) {
        ll a,b;cin >>a>>b;
        a--;b--;
        g[a][b]=g[b][a]=true;
    }
    vector<ll>ord(n);
    for (int i = 0; i < n; ++i) {
        ord[i]=i;
    }
    ll res=0;
    do{
        if(ord[0]!=0)break;
        bool ok=true;
        for (int i = 0; i+1 < n; ++i) {
            ll from=ord[i];
            ll to=ord[i+1];
            if(!g[from][to])ok=false;
        }
        if(ok)res++;
    }while(next_permutation(all(ord)));
    cout <<res<<endl;
    return 0;
}