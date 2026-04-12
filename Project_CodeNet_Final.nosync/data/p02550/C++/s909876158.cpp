#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    ll n,m,x,s=0;
    cin >>n>>x>>m;
    vector<Pl>memo(m);
    for (ll i=0; i <n; ++i) {
        if(memo[x].first){//衝突したら
            auto t=i-memo[x].first,c=(n-1-i)/t;
            //t 周期　c 何回そのループできるか
            i+=t*c;
            s+=(s-memo[x].second)*c;
        }
        else {
            memo[x]={i,s};
        }
        s+=x;
        x*=x;x%=m;
    }
    cout <<s<<endl;
}