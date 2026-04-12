#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
int main(){
    long long N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] *= -1;
    }
    std::vector<int> dp(N, INF);
    int l = INF;
    for(int i = 0; i < N; i++){
        int index = upper_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        dp[index] = A[i];
    }
    int ans = 0;
    for(int i = 0 ; i < N; i++){
        if(dp[i] != INF) ans++;
        else break;
    }
    cout << ans << endl;
}