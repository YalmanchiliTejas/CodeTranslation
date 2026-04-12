#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

//long longのシフト演算には気をつけよう

ll a[100], p[100];

ll f(ll n, ll x){
    if(n == 0) return 1;

    if(x == 1) return 0;
    else if(x <= 1+a[n-1]) return f(n-1, x-1);
    else if(x == 2+a[n-1]) return p[n-1]+1;
    else if(x <= 2+2*a[n-1]) return p[n-1]+1 + f(n-1, x-2-a[n-1]);
    else return 2*p[n-1]+1;
}

int main(){
    ll n, x; cin >> n >> x;
    a[0] = 1, p[0] = 1;

    for(int i=1; i<=n; i++) a[i] = 2*a[i-1] + 3, p[i] = 2*p[i-1] + 1;

    cout << f(n, x) << endl;
}