#include <bits/stdc++.h>
//#define int long long
#define MOD 1000000007
using namespace std;

string s;
int dp[10010][110],f[10010][110],d,sm[10010];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	cin>>d;
	dp[0][0]=1;
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<d;j++){
			int w=0;
			if(i==1) w=1;
			for(int k=w;k<=9;k++){
				int val=j+k;
				val%=d;
				dp[i][val]+=dp[i-1][j];
				if(dp[i][val]>=MOD) dp[i][val]-=MOD;
			}
		}
	}
	f[0][0]=1;
	for(int i=1;i<=s.size();i++){
		for(int j=0;j<d;j++){
			for(int k=0;k<=9;k++){
				int val=j+k;
				val%=d;
				f[i][val]+=f[i-1][j];
				if(f[i][val]>=MOD) f[i][val]-=MOD;
			}
		}
	}
	for(int i=1;i<=s.size();i++) sm[i]=sm[i-1]+(s[i-1]-'0');
	int ans=0;
	for(int i=1;i<=s.size();i++){
		int val=sm[i];
		val%=d;
		for(int j=s[i-1]-'0'+1;j<=9;j++){
			val++;
			val%=d;
			ans+=f[s.size()-i][(d-val)%d];
			if(ans>=MOD) ans-=MOD;
		}
	}
	int sum=0;
	for(int i=1;i<=s.size();i++){
		sum+=dp[i][0];
		if(sum>=MOD) sum-=MOD;
	}
	cout<<(sum-ans+MOD)%MOD<<endl;
	return 0;
}