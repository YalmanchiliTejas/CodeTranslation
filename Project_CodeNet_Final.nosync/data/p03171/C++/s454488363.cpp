#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[3007][3007];
bool vis[3007][3007];
int arr[3007];

ll rec( int l, int r )
{
//    cout<<l<<" "<<r<<endl;
    if( l>r )
        return 0;
    if( l==r )
        return arr[l];

    if( vis[l][r] )
        return dp[l][r];

    ll ret= -1e18;
    ll x= 0;
    ret= max( ret, arr[l]-rec(l+1,r) );
    ret= max( ret, arr[r]-rec(l,r-1) );

    vis[l][r]= 1;

    return dp[l][r]= ret;
}

int main()
{
    int n;
    cin>>n;

    for( int i=0;i<n;i++ )
        cin>> arr[i];

    cout<< rec( 0,n-1 ) <<endl;
}
