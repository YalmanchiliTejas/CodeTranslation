#include<bits/stdc++.h>
using namespace std;
string a;
int k,n;
long long dp[102][2][100000];
long long solve(int pos,int tight,int cnt){
	if(cnt>k) return 0;
	if(n==pos) return (cnt==k)?1:0;
	if(dp[pos][tight][cnt]!=-1)	return dp[pos][tight][cnt];
	long long ret=0;
	for(int i=0;i<10;i++){
		if(tight&&i>a[pos]-'0') break;
		int nxt_cnt=cnt+(i>0);
		int nxt_tight=tight&&i==(a[pos]-'0');
		ret+=solve(pos+1,nxt_tight,nxt_cnt);
	}
	return dp[pos][tight][cnt]=ret;
}

int main()
{
	cin>>a>>k;
	n=a.size();
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,1,0);
}