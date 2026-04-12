#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>


#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

template<class T> inline bool chmin(T &a, T b) { if(a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T &a, T b) { if(a < b){ a = b; return true; } return false; }

// const int INF = 1001001001;
// long long max => LLONG_MAX

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int r, g, b; cin >> r >> g >> b;
    int ans = r * 100 + g * 10 + b;
    if(ans %4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
