#include <bits/stdc++.h>

using namespace std;

const int maxn = 3010;

long long int dp[maxn][maxn];

main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int n;

    cin >> n;

    vector<long long int> vet(n+1);

    for(int i=1; i<=n; i++) cin >> vet[i];

    for(int l=n; l>=1; l--){
        for(int r=l; r<=n; r++){
            if(l==r) dp[l][r] = vet[l];
            else dp[l][r] = max(vet[l] - dp[l+1][r], vet[r] - dp[l][r-1]);
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}
