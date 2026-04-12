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
    ll s[N], ans = 0;
    rep(i, N) cin >> s[i];
    //A-B=iと固定する
    rep2(i, 1, N-1){
        vector<ll> l((N-1)/i+2), r((N-1)/i+2);
        //l[j](r[j]):=0(N-1)からiごとにj個取ったものの総和
        l[0] = r[0] = 0;
        rep(j, (N-1)/i+1){
            l[j+1] = l[j]+s[i*j];
            r[j+1] = r[j]+s[N-1-i*j];
        }
        //N-1=j*(A-B)+A
        rep(j, N/i){
            int A = N-1-j*i, B = A-i;
            if(B < 0) continue;
            if((N-1)%i == 0 && 2*i*j >= N-1) continue;
            ans = max(ans, l[j+1]+r[j+1]);
        }
    }
    cout << ans << endl;
}