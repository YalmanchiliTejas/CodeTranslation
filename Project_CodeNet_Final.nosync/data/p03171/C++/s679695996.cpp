#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define N 3003
#define M 30
#define ll long long 
#define ld long double
#define pb push_back
#define ff first
#define ss second

ll dp[N][N], a[N];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, l, r, i;
    cin>>n;
    for(i=0; i<n; i++){
        cin>>a[i];
    }
    for(l=n-1; l>=0; l--){
        for(r=l; r<n; r++){
            if(l == r) dp[l][r] = a[l];
            else{
                dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
            }
        }
    }
    cout<<dp[0][n-1];
    return 0;
}