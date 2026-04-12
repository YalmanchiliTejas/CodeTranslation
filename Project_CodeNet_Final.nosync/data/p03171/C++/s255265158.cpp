#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll dp[3001][3001][2];

ll recurse(int l, int r,int turn, vector<ll> &arr)
{
    if(l>r) return 0;
    if (dp[l][r][turn] != -1) return dp[l][r][turn];
    else
    {
        if(turn == 1) return dp[l][r][turn] = max(recurse(l+1,r,0,arr)+arr[l],recurse(l,r-1,0,arr)+arr[r]);
        else return dp[l][r][turn] = min(recurse(l+1,r,1,arr),recurse(l,r-1,1,arr));
    }
    
}

int main(int argc, char const *argv[])
{
    int n,temp;
    cin >> n;
    vector<ll> arr(n,0);
    ll sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[i] = temp;
        sum+= temp;
    }

    for(int i =0 ; i <= n ; i++)for(int j =0; j <=n ;j++)for(int k=0 ; k<=2 ;k++) dp[i][j][k] = -1;

    ll x = recurse(0,n-1,1,arr);
    ll y = sum -x ;

    cout << x-y;
    
    return 0;
}
