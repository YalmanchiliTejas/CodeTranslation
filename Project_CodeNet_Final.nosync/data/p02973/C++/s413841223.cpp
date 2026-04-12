#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define mp make_pair
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int main(){
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
    }

    map<ll, ll> ma;
    ll ans = 0;
    for(auto&& a : A){
        auto iter = ma.upper_bound(-a);
        if(iter != ma.end()){
            auto p = *iter;
            ll key = p.first;
            ma[key]--;
            if(ma[key] == 0)
                ma.erase(key);
        }
        ma[-a]++;
    }

    for(auto&& p : ma)
        ans += p.second;
    cout << ans << endl;
    return 0;
}
