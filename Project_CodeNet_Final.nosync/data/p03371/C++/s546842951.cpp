#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
    int ulim = max(X, Y)*2;
    int ans = INF;
    for(int i = 0; i <= ulim; i+=2){
        int remA = X - i/2;
        int remB = Y - i/2;
        ans = min(ans, i*C + max(0, remA)*A + max(0, remB)*B);
    }
    cout << ans << endl;
    return 0;
}