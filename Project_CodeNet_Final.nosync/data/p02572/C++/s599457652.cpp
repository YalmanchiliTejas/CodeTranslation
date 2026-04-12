#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9+7;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    ll sum[N]; memset(sum, 0, sizeof(sum));
    for(int i = 0; i < N; ++i){
        sum[i] += A[i];
        if(i != 0) sum[i] += sum[i-1];
    }
    ll ans = 0;
    for(int i = 0; i < N-1; ++i){
        ll tmp = sum[N-1] - sum[i];
        tmp %= INF;
        ans += tmp*A[i];
        ans %= INF;
    }
    cout << ans << endl;
    return 0;
}