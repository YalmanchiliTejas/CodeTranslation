#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fi first
#define sec second

ll n,m,k,a,b,x,x2,y,y2,sol=0,cnt,sad,koliko;
char c;
string s;
vector <ll> V;
ll dp[200010][3][2];

int main()
{
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> x;
        V.push_back(x);
    }

    dp[0][0][0]=-LLONG_MAX;
    dp[0][1][0]=0;
    dp[0][2][0]=-LLONG_MAX;
    dp[0][0][1]=V[0];
    dp[0][1][1]=-LLONG_MAX;
    dp[0][2][1]=-LLONG_MAX;

    for (int i=1;i<n;i++){
        x=V[i];

        dp[i][0][0]=dp[i-1][0][1];
        dp[i][1][0]=max(dp[i-1][1][1],dp[i-1][0][0]);
        dp[i][2][0]=max(dp[i-1][2][1],dp[i-1][1][0]);
        dp[i][0][1]=dp[i-1][0][0]+x;
        dp[i][1][1]=dp[i-1][1][0]+x;
        dp[i][2][1]=dp[i-1][2][0]+x;
    }

    if (n%2==0){
        cout << max(dp[n-1][0][0], dp[n-1][1][1]);
    }
    else{
        cout << max(dp[n-1][1][0], dp[n-1][2][1]);
    }
}
