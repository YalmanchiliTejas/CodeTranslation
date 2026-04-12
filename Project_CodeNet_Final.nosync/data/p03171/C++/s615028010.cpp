#include<bits/stdc++.h>
#define ll long long int
using namespace std;
#define FOR(i,a,b) for(long long int i=a;i<b;i++)
#define sz(s) (long long int)(s).size()
#define pb push_back
#define mp make_pair
const ll inf = 1000000000;
const ll MOD = 1000000007;
ll a[3001], X=0, Y=0, sum = 0;
ll dp[3001][3001];
ll recur(ll flag, ll start, ll end){
	if(start > end)return 0;
	if(dp[start][end] != 0){
		return dp[start][end];
	}else if(flag){
		dp[start][end] = max(a[start] + recur(!flag, start+1, end), a[end] + recur(!flag, start, end-1));		
		return dp[start][end];
	}
	else{ 
		dp[start][end] = min(recur(!flag, start+1, end) - a[start], recur(!flag, start, end-1) - a[end]);
		return dp[start][end];
	}		
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    register ll i,j,k,x,y,m,n,t,q,temp,sum=0,count=0,f=1;
    cin>>n;
    // memset(dp, inf, sizeof(dp));
    for(i=0;i<n;i++){
    	cin>>a[i];
    	sum += a[i];
    }
    x = recur(1, 0, n-1);    
    cout<<x;    
}    
    