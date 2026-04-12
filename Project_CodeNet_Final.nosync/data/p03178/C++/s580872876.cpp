#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#include<string>
#include<set>
#include<numeric>
#include<map>
#include<iostream>
#include<iomanip>
using namespace std;
#define rep(i,n) for(int i = 0;i<((int)(n));i++)
#define reg(i,a,b) for(int i = ((int)(a));i<=((int)(b));i++)
#define irep(i,n) for(int i = ((int)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(int i = ((int)(b));i>=((int)(a));i--)
typedef long long ll;
typedef pair<ll, ll> mp;

/*
WA
dp[総和をDで割った余りがi][0~9まで自由に選べるかどうか]
*/

ll d,dp[110][2],dp2[110][2],mod=1e9+7,ans;
string s;

int main(void){
	cin>>s>>d;
	//
	rep(j,d)rep(k,2)dp[j][k]=0;
	dp[0][0]=1;
	//
	rep(i,s.size()){
		rep(j,d)rep(k,2)dp2[j][k]=0;
		rep(j,d){//前からの余り
			rep(k,10){//今の桁の数
				ll res = (j+k)%d;
				//自由に選べるやつの遷移先
				dp2[res][1]=(dp2[res][1]+dp[j][1])%mod;
				//自由に選べないやつの遷移先
				if(k<s[i]-'0'){//Kより小さい数字にするなら
					dp2[res][1]=(dp2[res][1]+dp[j][0])%mod;
				}else if(k==(s[i]-'0')){
					dp2[res][0]=(dp2[res][0]+dp[j][0])%mod;
				}
			}
		}
		rep(j,d)rep(k,2)dp[j][k]=dp2[j][k];
	}
	//dp[0][0]+dp[0][1]がちょうど1e9+7になったらやばいので
	ans=(mod+dp[0][0]+dp[0][1]-1)%mod;//0は除く
	cout<<ans<<endl;
	return 0;
}