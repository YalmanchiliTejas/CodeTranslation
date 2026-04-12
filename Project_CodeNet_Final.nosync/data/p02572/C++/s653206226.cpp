#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e18;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
signed main() {
    int N;
    cin >> N;
    vector<int>A(N);
    int res = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] %= mod;
        res += A[i];
        res %= mod;
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        res = (res+mod-A[i])%mod;
        ans += A[i]*res%mod;
        ans %= mod;
    }
    cout << ans << endl;
}