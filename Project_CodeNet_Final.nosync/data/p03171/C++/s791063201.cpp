#include<bits/stdc++.h>
#define mod 1000000007 
#define eps 1e-9
#define PI 3.14159265358979323846
#define F first
#define S second
#define ll long long
#define pb push_back
#define mp make_pair
#define Fr(i,a,b) for(int i=a;i<=b;i++)
#define RF(i,a,b) for(int i=a;i>=b;i--)
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pii>
#define int long long
using namespace std;
vi bb;
int dp[3005][3005][2];
int rec(int l,int r,int flag){
	if(l>r){return 0;}
	if(dp[l][r][flag]!=-1)return dp[l][r][flag];
	return dp[l][r][flag]=bb[r+1]-bb[l]-min(rec(l+1,r,!flag),rec(l,r-1,!flag));
}
signed main(){
    
    int t=1;
    //cin>>t;
    int coco=1;
    while(t--){
        int n;
        cin>>n;
        bb.pb(0);
        int prev=0;int x;
        for(int i=0;i<n;i++){
        	cin>>x;
        	prev+=x;
        	bb.pb(prev);
        }
        memset(dp,-1,sizeof(dp));
        int ans=rec(0,n-1,1);
        cout<<ans-(bb[n]-ans);
    }   
    return 0;
}