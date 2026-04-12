//#define sort(nums) sort(nums.begin(),nums.end())
#include <bits/stdc++.h>
#define mod 1000000007
#define deb(x) cout<<#x<<" "<<x<<endl
using namespace std;
using ll = long long int;

void jets(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll dp[3002][3002];

ll solve(vector<int>& vec, int i, int j){
	if(i>j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll op1=vec[i]+min(solve(vec,i+2,j),solve(vec,i+1,j-1));
	ll op2=vec[j]+min(solve(vec,i,j-2),solve(vec,i+1,j-1));
	return dp[i][j]=max(op1,op2);
}


int main(){
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    jets();
    int n;
    cin>>n;
    vector<int> vec(n);
    ll sum=0;
    memset(dp,-1,sizeof dp);
    for(int i=0;i<n;i++){
    	cin>>vec[i];
    	sum+=vec[i];
    }
    ll res=solve(vec,0,n-1);
    cout<<res-(sum-res);
    return 0;
}