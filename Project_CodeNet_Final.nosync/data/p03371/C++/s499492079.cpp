#include <bits/stdc++.h>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define rep(i, n) for (int i = 0; i < (int)n; i++)
typedef long long ll;
const ll MOD = 1e9+7;
const int inf = 1000000;
const int minf = -1000000;
const ll lnf = 1e9;
const ll mlnf = -1e9;

void debug_vector(vector<int>& v){
    int n = v.size();
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

void solve();

int main(void){
    solve();
    return 0;
}
void solve(){
    int A, B, C, X, Y;
    cin >> A >> B >> C >> X >> Y;
    ll ans = 0;
    if (A + B < 2 * C){
        ans = A * X + B * Y;
    }else{
        ans = min(X, Y) * 2 * C;
        int tmp = abs(X - Y);
        if (X > Y){
            ans += min(tmp * 2 * C, tmp * A);
        }else{
            ans += min(tmp * 2 * C, tmp * B);
        }
    }


    printf("%lld\n", ans);
}