#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> X(N),t;
    rep(i,N) cin >> X[i];
    t = X;
    sort(ALL(t));
    ll ans = t[(N/2) - 1];
    rep(i,N){
        // i 番目の数を除いた数列の中央値
        if(X[i]>ans)cout << ans << endl;
        else cout << t[(N/2)] << endl;
    }
}