#include<bits/stdc++.h>

#define ll long long
#define ff first
#define ss second
#define pb push_back

using namespace std;

const int N  = 1e6 + 69, INF = 1e9;

const ll INFLL = 1e18;

int n, k;
ll dp[3009][3009],A[N];

int main(){

        cin >> n;

        for(int i = 1; i <= n; i++){
                cin >> A[i];
        }

        for(int cnt = 1; cnt <= n; cnt++){
                for(int l = 1; l <= n; l++){
                        int r = l + cnt - 1;
                        if(r > n) continue;
                        if(l == r){
                                dp[l][r] = A[l];
                        } else {
                                dp[l][r] = max(A[l] - dp[l+1][r], A[r] - dp[l][r-1]);
                        }
                }
        }

        cout << dp[1][n] << endl;
}
