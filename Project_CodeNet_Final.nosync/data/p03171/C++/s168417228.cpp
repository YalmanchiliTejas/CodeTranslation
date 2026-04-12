#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<stack>
#include<set>
#include<string.h>
#include<map>
#include<queue>
#include<vector>
#define pb push_back
#define eb emplace_back
#define ins insert 
#define mp make_pair
#define ll long long 
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define inf 1000000000000000000
#define M 1000000007
using namespace std;
void solve(){
	ll n,k;
	cin>>n;
	ll a[n];
	for (int i = 0; i <n; ++i)
	{
		cin>>a[i];
	}
	ll dp[n+5][n+5];
	for (int i =n-1; i>=0; --i)
	{
		for (int j = i; j<n; ++j)
		{
			if(j==i)
				dp[i][j]=a[j];
			else
				dp[i][j]=max(a[i]-dp[i+1][j],a[j]-dp[i][j-1]);
		//	cout<<dp[i][j]<< " ";
		}
		//cout<<endl;
	}
	cout<<dp[0][n-1];
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0 ;
}
