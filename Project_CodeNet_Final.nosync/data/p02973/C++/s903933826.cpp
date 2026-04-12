#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<vector<ll> > Graph;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e16;

int n;

int main(){
    cin >> n;
    vector<ll>a(n);
    rep(i,n){
        cin >> a[i];
    }
    multiset<ll>ms;
    rep(i,n){
        ll now = a[i];
        auto itr = ms.lower_bound(now);
        if(itr==ms.begin()){
            ms.emplace(now);
        }
        if (itr!=ms.begin()){
            itr--;
            ms.erase(itr);
            ms.emplace(now);
        }
    }
    cout << ms.size() << endl;
    return 0;
}

