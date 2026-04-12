#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", ans);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll rec(ll n, ll x) {
    if (n == 0) return 1;
    if (x == 1) return 0;
    ll len = (1LL << (n + 1)) - 3;
    ll Pnum = (1LL << n) - 1;
    if (x <= len + 1) return rec(n - 1, x - 1);
    else if (x == len + 2) return Pnum + 1;
    else if (x <= (len + 1) * 2) return Pnum + 1 + rec(n - 1, x - len - 2);
    else return Pnum * 2 + 1;    
}

int main(void) {
    ll n, x;
    cin >> n >> x;

    cout << rec(n, x) << endl;
    return 0;
}