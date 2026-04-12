#include <bits/stdc++.h>
#define rep(i,n) for (ll i=0; i < (n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline bool change(T& a, T b) { if (a != b) { a = b; return 1; } return 0; }
using namespace std;
typedef long long ll;

int main(){
    int n; cin >> n;
    if(n>=30) cout << "Yes" <<endl;
    else cout << "No" <<endl;
}