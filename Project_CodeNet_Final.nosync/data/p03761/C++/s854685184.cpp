#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;


int main() {
    ll n;
    cin >> n;
    vector<string> S(n);
    string ans;
    rep(i,n) cin >> S[i];

    int ans_chr[26];
    rep(i,26) ans_chr[i] = MOD;

    rep(i,n){
        int tmp_chr[26] = {0};
        rep(j,S[i].size()){
            tmp_chr[(S[i][j] - 'a')]++;
        }
        rep(j,26) ans_chr[j] = min(ans_chr[j],tmp_chr[j]);
    }

    rep(i,26){
        rep(j,ans_chr[i]) ans += ('a' + i);
    }

    cout << ans;
    //printf("%.15lf", ans);
    cout << "\n";
    return 0;
}
