#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }


int main(){
    cin.tie(0);
   	ios::sync_with_stdio(false);
    
    ll A, B, C, X, Y;

    cin >> A >> B >> C >> X >> Y;

    ll ans_case1;//全部 A, Bのみで買う
    ll ans_case2;// A, B, Cで買う
    ll ans_case3;// Cのみで買う
    ll ans = INF;

    ans_case1 = A * X + B * Y;
    chmin(ans, ans_case1);

    ans_case2 = A * (X - min(X, Y)) + B * (Y - min(X, Y)) + 2 * C * min(X, Y);
    chmin(ans, ans_case2);
    
    ans_case3 = 2 * C * max(X, Y);
    chmin(ans, ans_case3);
    
    cout << ans << endl;
    

    return 0;
}
