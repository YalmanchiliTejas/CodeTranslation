#include<bits/stdc++.h>
#define int long long 
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(a) a.begin(),a.end()
#define ld long double
#define ub upper_bound
#define lb lower_bound
#define pii pair<int,int>
using namespace std;
const int N = 103;
int dp[N][4];
int dp2[N][4][2];
string s;
int k;
int req;
int solve1(int idx,int nz){
	if(idx>req){
		if(nz == k)
			return 1;
		return 0;
	}
	if(nz>k)
		return 0;
	if(dp[idx][nz]!=-1)
		return dp[idx][nz];
	int ans = 0;
	for(int i=0;i<=9;i++){
		if(idx == 1 && i == 0)
			continue;
		if(i == 0)
			ans+=solve1(idx+1,nz);
		else ans+=solve1(idx+1,nz+1);
	}
	dp[idx][nz] = ans;
	return ans;
}
int solve2(int idx,int nz,int flag){
	if(idx>req){
		if(nz == k){
			return 1;
		}
		return 0;
	}
	if(nz>k)
		return 0;
	if(dp2[idx][nz][flag]!=-1)
		return dp2[idx][nz][flag];
	int ans = 0;
	if(flag == 0){
		for(int i = 0;i<=(s[idx-1]-'0');i++){
			if(idx == 1 && i == 0)
				continue;
			if(i<(s[idx-1]-'0')){
				if(i == 0)
					ans+=solve2(idx+1,nz,1);
				else ans+=solve2(idx+1,nz+1,1);
			}
			else{
				if(i == 0)
					ans+=solve2(idx+1,nz,0);
				else ans+=solve2(idx+1,nz+1,0);
			}
		}
	}
	else{
		for(int i=0;i<=9;i++){
			if(idx == 1 && i == 0)
				continue;
			if(i == 0)
				ans+=solve2(idx+1,nz,1);
			else ans+=solve2(idx+1,nz+1,1);
		}
	}
	dp2[idx][nz][flag] = ans;
	return ans;
}
signed main()
{
    fast;
    cin>>s;
    cin>>k;
    int n = s.size();
    int ans = 0;
    for(int i=1;i<=n-1;i++){
    	memset(dp,-1,sizeof(dp));
    	req = i;
    	ans+=solve1(1,0);
    }
    req = n;
    memset(dp2,-1,sizeof(dp2));
    ans+=solve2(1,0,0);
    cout<<ans;
}   