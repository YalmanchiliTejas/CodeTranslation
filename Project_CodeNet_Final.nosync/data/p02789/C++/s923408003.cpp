#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0;i < n;++i)
#define rep2(i,n,m) for(int i = n;i < m;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n,w;
    cin >> n >> w;
    if(n == w) cout << "Yes" << endl;
    else cout << "No" << endl;

    cout << endl;
    return 0;
}