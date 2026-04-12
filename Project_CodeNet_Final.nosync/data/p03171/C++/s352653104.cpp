#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a[5050];
ll dp[5005][5005];

int main()
{
    int n;
    cin >> n;
    for(int i = 1 ; i <= n;i++){
        scanf("%d",&a[i]);
    }

    for(int i = 1; i <= n;i++){
        dp[i][i] = a[i];
    }

    for(int i = n - 1; i ; i--){
        for(int j =i + 1; j <= n;j++){
            dp[i][j] =   max( a[i] - dp[i+1][j] , a[j] - dp[i][j-1] );
        }
    }

    cout << dp[1][n];


    return 0;
}
