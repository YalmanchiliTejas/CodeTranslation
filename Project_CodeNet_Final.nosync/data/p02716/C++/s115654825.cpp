#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,x,sol=0;
vector<ll>V;
ll dp[200005][3][2];

int main() {
    cin >> n;
    for (int i=0;i<n;i++) {
        cin >> x;
        V.push_back(x);
    }
    dp[0][0][0]=INT_MIN;
    dp[0][0][1]=V[0];
    dp[0][1][0]=0;
    dp[0][1][1]=INT_MIN;
    dp[0][2][0]=INT_MIN;
    dp[0][2][1]=INT_MIN;

    for (int i=1;i<n;i++) {
        dp[i][0][0]=dp[i-1][0][1];
        dp[i][1][0]=max(dp[i-1][1][1],dp[i-1][0][0]);
        dp[i][2][0]=max(dp[i-1][2][1],dp[i-1][1][0]);
        dp[i][0][1]=dp[i-1][0][0]+V[i];
        dp[i][1][1]=dp[i-1][1][0]+V[i];
        dp[i][2][1]=dp[i-1][2][0]+V[i];
    }

//    for (int i=0;i<2+n%2;i++) {
//        for (int j=0;j<2;j++) {
//            sol=max(sol,dp[n-1][i][j]);
//        }
//    }

    if (n%2==0) {
        sol=max(dp[n-1][0][0],dp[n-1][1][1]);
    }
    else {
        sol=max(dp[n-1][1][0],dp[n-1][2][1]);
    }
    cout << sol;
}


