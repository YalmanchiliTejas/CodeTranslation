//Robs Code
/***********HEADER***************/
#include <iostream>
#include <bitset>
#include <deque>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <queue>
#include <map>
/***********MACROS***************/
#define int long long int
#define fri(l,k) for (i=l;i<=k;i++)
#define frj(l,k) for (j=l;j>=k;j--)
#define fij(a,b,l,k) for(i=a;i<=b;i++) for(j=l;j<=k;j++)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define endl "\n"
#define pb push_back
#define _1 first
#define _2 second
#define pii pair<int,int>
using namespace std;
int n,m,i,j,l,k,x,y,a,b,cnt[3],sum[3];
/***********MAIN**************/
int v[(int)3e3+20];
int dp[(int)3e3+20][(int)3e3+20][3];
int brute(int i,int j,int player){
	if(i > j){
		return 0;
	}
	if(dp[i][j][player] != -1){
		return dp[i][j][player];
	}
	int ans = 0;
	if(player == 1){
		ans = max(v[i]+brute(i+1,j,player^3),v[j]+brute(i,j-1,player^3));
	}else{
		ans = min(-v[i]+brute(i+1,j,player^3),-v[j]+brute(i,j-1,player^3));
	}
	dp[i][j][player] = ans;
	return ans;
}
signed main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	memset(dp,-1,sizeof dp);
	cout<<brute(0,n-1,1);
	return 0;
}
//.........