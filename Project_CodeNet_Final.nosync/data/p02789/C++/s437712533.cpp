#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
#define repi(i,a,b) for(ll i = (ll)(a); i < (ll)(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;
int main(){
    int n,m; cin >> n >> m;
    if(n==m) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}