#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const long long inf2=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int dp[100001][101][3];
//dp[i][j]:number with j digits mod D=i;
int d;
string s;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>s>>d;
	//0:<s 1:==s 2:>s
	s=" "+s;
	dp[0][0][1]=1;
	for(int i=1;i<s.size();i++){
		for(int j=0;j<d;j++){
			for(int k=0;k<10;k++){
				dp[i][(j+k)%d][0]+=dp[i-1][j][0];
				dp[i][(j+k)%d][0]%=mod;
				if(k<s[i]-'0')dp[i][(j+k)%d][0]+=dp[i-1][j][1],dp[i][(j+k)%d][0]%=mod;
				else if(k==s[i]-'0')dp[i][(j+k)%d][1]+=dp[i-1][j][1],dp[i][(j+k)%d][1]%=mod;
				else dp[i][(j+k)%d][2]+=dp[i-1][j][1],dp[i-1][j][1]%=mod;
				dp[i][(j+k)%d][2]+=dp[i-1][j][2];
				dp[i][(j+k)%d][2]%=mod;
			}
		}
	}
	ll ans=0;
	ans+=dp[s.size()-1][0][0];ans+=dp[s.size()-1][0][1];ans%=mod;
	cout<<(ans+mod-1)%mod<<endl;
	return 0;
}