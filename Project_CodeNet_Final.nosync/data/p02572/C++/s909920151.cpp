#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
using ll = long long;
const int inf = (int)1e10;
const int mod = (int)1e9 + 7;

int n;
int a[2*(int)1e5 + 1];
int main(){
    cin >> n;
    rep(i, n) cin >> a[i];

    ll sum_a = 0, res = 0;
    rep(i, n) sum_a += a[i];
    rep(i, n - 1){
        sum_a -= a[i];
        res = (res + (a[i] %mod) * (sum_a %mod)) %mod;
    }
    cout << res << endl;
}