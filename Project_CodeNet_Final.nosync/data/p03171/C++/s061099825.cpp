#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

template <typename T>
void print(T vec) { for(auto i : vec) cout<<i<<" ";}
template <typename T>
void print2D(T matrix) {for(auto vec:matrix) {print(vec);cout<<'\n';}}

int main() {
    int n;
    cin>>n;
    vector<ll> A(n);
    for(int i=0;i<n;i++) cin>>A[i];

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));
    for(int L = n-1; L >= 0; L--) {
        for(int R = L; R<n;R++) {
            if(L==R) dp[L][R] = A[L];
            else{
                dp[L][R] = max(A[L] - dp[L+1][R], A[R] - dp[L][R-1]);
            }
        }
    }
    //print2D(dp);
    //for(auto i : A) cout<<i<<" ";
    cout<<dp[0][n-1]<<'\n';
    return 0;
}