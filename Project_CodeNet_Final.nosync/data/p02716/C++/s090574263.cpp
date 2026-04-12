#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb(x) push_back(x)
#define all(x) x.begin(), x.end()
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = 1e9;
const ll INF = 1e18;
const ld EPS = 1e-10;

int main(){
    int N;
    cin >> N;
    ll A[N];
    rep(i, N) cin >> A[i];
    if(N%2 == 0){
        ll l[N/2+1], r[N/2+1];
        l[0] = r[0] = 0;
        rep2(i, 1, N/2){
            l[i] = l[i-1]+A[(i-1)*2];
            r[i] = r[i-1]+A[(i-1)*2+1];
        }
        //rep(i, N/2+1) cout << l[i] << ' ' << r[i] << endl;
        ll ans = l[N/2];
        rep(i, N/2+1){
            ll tmp = l[i]+r[N/2]-r[i];
            ans = max(ans, tmp);
        }
        cout << ans << endl;
        return 0;
    }
    ll M[N/2];
    M[0] = A[1]-A[0];
    rep2(i, 1, N/2-1){
        M[i] = A[2*i+1]-A[2*i];
        if(M[i-1] > 0) M[i] += M[i-1];
    }
    //rep(i, N/2) cout << M[i] << ' ';
    //cout << endl;
    ll ans, m = INF, sum = 0;
    rep(i, N){
        if(i%2 == 0){
            sum += A[i], m = min(m, A[i]);
        }
    }
    ans = sum-m;
    rep(i, N/2){
        ll tmp = sum-A[(i+1)*2] + M[i];
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}