#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); i++)
#define INF 10000000000
#define MOD 1000000007
using ll = long long;
using pint = pair<int, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<int>>;

int main(){
    int N; cin>>N;
    vector<ll> S,B;//smaller,bigger

    vector<pll> x(N),y(N);//smaller,bigger
    rep(i,N){
        ll a,b; cin>>a>>b;
        if(a>b) swap(a,b);
        x[i] = {a,i};
        y[i] = {b,i};
        B.push_back(b);
        S.push_back(a);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    bool flag = (x[0].second==y[N-1].second);
    ll res1 = 0, res2 = 0;
    res1 = (x[N-1].first - x[0].first) * (y[N-1].first - y[0].first);
    if(flag){
        cout<<res1<<endl;
        return 0;
    }
    res2 = y[N-1].first - x[0].first;
    
    ll Bmin = min(x[1].first,B[x[0].second]), Bmax = max(x[N-1].first,B[x[0].second]);
    rep1(i,N-1){
        // cout<<Bmin<<" "<<Bmax<<endl;
        if(Bmin!=x[i].first)break;
        if(Bmin==S[y[N-1].second])break;
        if(Bmin==x[i].first&&B[x[i].second]<=Bmax){
            Bmin = min({y[0].first,B[x[i].second],x[i+1].first});
        }else{
            break;
        }
    }
    res2 *= (Bmax - Bmin);
    cout<<min(res1,res2)<<endl;
}
