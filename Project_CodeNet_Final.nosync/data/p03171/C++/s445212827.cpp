#include<bits/stdc++.h>
using namespace std;

 
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

 
int N;
vector<long long> a;
vector< vector<long long> > dp;

//dp[l][r]:[l, r)の範囲における二人が最適な行動をした時のX-Yの値
//dp[l][r] = max(dp[l][r-1]+a[r-1], dp[l+1][r]+a[l]) (大郎)
//dp[l][r] = min(dp[l][r-1]-a[r-1], dp[l+1][r]-a[l]) (次郎)

long long rec(int l, int r) {
    if (dp[l][r] != -1) return dp[l][r];
    if (r-l == 0) return 0; //数字が残っていない時
    else {
        if ((r-l) % 2 == N % 2) { //大郎のturn
            dp[l][r] = max(rec(l+1, r)+a[l], rec(l, r-1)+a[r-1]);
        }
        else { //次郎のturn
            dp[l][r] = min(rec(l+1, r)-a[l], rec(l, r-1)-a[r-1]);
        }
    }
    return dp[l][r];
}

int main() {
    cin >> N;
    a.resize(N);
    dp.resize(N+2, vector<long long> (N+2, -1));
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    long long ret = rec(0, N);
    cout << ret << endl;
    return 0;
}