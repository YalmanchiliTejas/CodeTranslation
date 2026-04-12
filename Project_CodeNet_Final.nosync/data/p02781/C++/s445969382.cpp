#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp setprecision
#define pb(x) push_back(x)
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ld, ld> pdd;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const string alpha = "abcdefghijklmnopqrstuvwxyz";

int main(){
    string s;
    ll k;
    cin >> s >> k;
    int n = s.size();
    ll a[n][k+1], b[n][k+1];
    fill(a[0], a[n], 0), fill(b[0], b[n], 0);
    int x = s[0]-'0';
    a[0][1] = 1;
    b[0][0] = 1;
    b[0][1] = x-1;
    rep2(i, 1, n-1){
        x = s[i]-'0';
        rep(j, k+1) b[i][j] += b[i-1][j];
        rep(j, k) b[i][j+1] += b[i-1][j]*9;
        if(x == 0){
            rep(j, k+1) a[i][j] += a[i-1][j];
            continue;
        }
        rep(j, k+1) b[i][j] += a[i-1][j];
        rep(j, k){
            b[i][j+1] += a[i-1][j]*(x-1);
        }
        rep(j, k){
            a[i][j+1] += a[i-1][j];
        }
    }
    cout << a[n-1][k]+b[n-1][k] << endl;
}