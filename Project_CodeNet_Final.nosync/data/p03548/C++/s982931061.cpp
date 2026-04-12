#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
    ll X, Y, Z;
    cin >> X >> Y >> Z;
    ll curr = 0;
    ll n = 0;
    for (ll i=0; i<100000000; i++){
        if (Z*(i+1) + i*Y <= X)n++;
        else break;
    }
    cout << n - 1<< endl;
}