#include<iostream>
#include<cstdio>

#include<vector>
#include<string>

#include<algorithm>
#include<cmath>

using namespace std;
typedef long long ll;
const ll INF = 1e9+1;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}

ll A,B,C,X,Y;

int main() {
    cin >> A >> B >> C >> X >> Y;
    ll res = 0;
    ll Z = min(X,Y);
    X = X - Z; Y = Y - Z;
    res += min(A+B,2 * C) * Z;
    
    res += min(A,2 * C) * X + min(B,2 * C) * Y;
    cout << res << endl;
}
