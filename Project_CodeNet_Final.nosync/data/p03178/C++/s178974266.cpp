#include <bits/stdc++.h>
using namespace std;
#define int long
const int YYQ=1e9+7;
int d,dp[10005][105][2];
string s;
signed main(){
	cin>>s>>d;
    dp[0][0][0]=1;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<d;j++){
			for(int k=0;k<2;k++){
				int r=9;
				if(k==0)	r=s[i]-'0';
				for(int S=0;S<=r;S++){
					int gk=k;
					if(S<s[i]-'0')	gk=1;
					dp[i+1][(j+S)%d][gk]=(dp[i+1][(j+S)%d][gk]+dp[i][j][k])%YYQ;
				}
			}
		}
	}
	int ans=(dp[s.size()][0][0]+dp[s.size()][0][1]+YYQ-1)%YYQ;
	cout<<ans<<endl;
    return 0;
}