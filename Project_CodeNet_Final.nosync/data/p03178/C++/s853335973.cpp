#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
string s;
int d;
const int mod=1000000007;
int dp[10002][102][2];
int f(int pos,int m,int b){
	if(pos==s.size()){
		return m==0;
	}
	int &ans=dp[pos][m][b];
	if(~ans)return ans;
	ans=0;
	if(b)
	{
		for(int i=0;i<10;i++){
			ans+=f(pos+1,(m+i)%d,b);
			if(ans>=mod)ans-=mod;
		}
	}else{
		for(int i=0;i<s[pos]-'0';i++){
			ans+=f(pos+1,(m+i)%d,1);
			if(ans>=mod)ans-=mod;
		}
		ans+=f(pos+1,(m+s[pos]-'0')%d,0);
		if(ans>=mod)ans-=mod;
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(dp,-1,sizeof dp);
	cin>>s>>d;
	int ans=f(0,0,0)-1;
	if(ans<0)ans+=mod;
	cout<<ans<<endl;
	return 0;
}