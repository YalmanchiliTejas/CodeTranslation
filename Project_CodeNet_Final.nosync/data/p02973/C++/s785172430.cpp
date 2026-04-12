#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll MOD = 1e9+7;
ll LLINF = 1LL << 60;
int INF = INT_MAX;

int main(){
    ll n; cin>>n;
    
    multiset<int> m;
    rep(i,0,n){
        ll x; cin>>x;
        auto it=m.lower_bound(x);
        if(it!=m.begin()) m.erase(--it);
        m.insert(x);
    }
    cout<<m.size()<<endl;
}