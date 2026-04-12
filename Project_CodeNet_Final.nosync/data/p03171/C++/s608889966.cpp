#include <bits/stdc++.h>

using namespace std;
template <typename T> void print(T vec) {for(auto d: vec) cout<<d<<' ';cout<<'\n';}
template<typename T> void print2D(T mat) {for(auto vec:mat) print(vec);}

typedef long long int ll;

int n;

void solution(vector<ll> &A) {
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1));
    for(int R = 0; R < n; R++) {
        for(int L = R; L >= 0; L--) {
            if(L == R) dp[L][R] = A[L];
            else dp[L][R] = max(A[L] - dp[ L + 1][R], A[R] - dp[L][R - 1]);
        }
    }
    cout<<dp[0][n - 1]<<'\n';
    // print2D(dp);
}


int main() {

    cin>>n;
    vector<ll> A(n);
    for(int i = 0; i< n;i++) cin>>A[i];
    solution(A);
    return 0;
}