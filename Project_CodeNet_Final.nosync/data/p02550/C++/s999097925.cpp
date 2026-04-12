#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define REP(i,a,b) for(int i=int(a);i<(int)b;++i)
#define Graph vector<vecctor<ll>>
#define pairs vector<pair<ll,ll>>
#define pb push_back



using namespace std;
using ll = long long;
const ll INF = 1e18;
const double PI = acos(-1);

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
const ll mod = 1e9 + 7;







int main(void)
{
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    ll n,x,m;
    cin >> n >> x >> m;
    vector<ll>a;
    ll as = x,sum = x,key=INF;
    a.pb(as);
    bool flag;
    set<ll>se;
    se.insert(as);
    rep(i,m){
        as = (as*as)%m;
        if(se.count(as) == 1){
            flag = false;
            key = as;
            break;
        }
        if(as == 0){
            flag = true;
            break;
        }
        a.pb(as);
        se.insert(as);
        sum += as; 
    }
    ll start = INF;
    if(flag){
        cout << sum << endl;
        return 0;
    }else{
        rep(i,a.size()){
            if(a[i] == key){
                start = i;
            }
        }
    }
    sum = 0;
    ll ans,sz = 0;
    rep(i,a.size()){
        if(i == start){
            ans = sum;
            sum = 0;
            sz = 0;
        }
        sz++;
        sum += a[i];

    }
    n -= start;
    ll sho = n/sz;
    ll amari = n%sz;
    ans += sho*sum;
    for(int i = 0;i < amari;++i){
        ans += a[i+start];
    }

    cout << ans << endl;
    return 0;
}