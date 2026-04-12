#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;

int n;
long long a[N];
long long dp[3001][3001];

int main(){
    cin>> n;
    for(int i = 1; i <= n; i++){
        cin>> a[i];
    }
    for(int L = n; L >= 1; L--){
        for(int R = L; R <= n; R++){
            if(L == R){
                dp[L][R] = a[L];
            }
            else{
                dp[L][R] = max(a[L] - dp[L + 1][R], a[R] - dp[L][R - 1]);
            }
        }
    }
    cout<< dp[1][n];
}
