#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
constexpr int INF = numeric_limits<int>::max() / 2;
constexpr long long INFL = numeric_limits<long long>::max() / 2;
constexpr int MOD = 1000000007;
using Graph = vector<vector<int>>;



int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    int H[N];
    rep(i,N) {
        cin >> H[i];
    }
    int s=0;
    int ans=0;
    rep(i,N){
        if(H[i]>=s) ans++;
        s=max(s,H[i]);
    }
    cout << ans << endl;



}
