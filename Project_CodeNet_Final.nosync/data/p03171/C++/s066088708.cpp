#include<bits/stdc++.h>
#define crap ios_base::sync_with_stdio(0);cin.tie(0)
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define endl "\n"
#define int ll

using namespace std;

const int N = 3005;
int A[N];
int dp[N][N];
int n;



int32_t main()
{
   
    crap;
    memset(dp,0,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++) cin>>A[i];

    for(int l=n-1;l>=0;l--){
    	for(int r=l;r<n;r++){
    		if(l==r) dp[l][r]=A[l];
    		else
    			dp[l][r]= max(A[l] - dp[l+1][r], A[r] -  dp[l][r-1]);
    	}
    }
    cout<<dp[0][n-1]<<endl;
}