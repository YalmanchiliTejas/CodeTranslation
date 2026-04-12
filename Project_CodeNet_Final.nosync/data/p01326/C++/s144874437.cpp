#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
typedef pair<int,int>P;
typedef pair<int,P>P2;
#define F first
#define S second

int calc1(string s){
	if(s[0]=='1')return 0;
	int x=1;
	r(i,7){
		if(s[i+1]=='x')x*=2;
	}
	return x;
}

int calc2(string s){
	int y=0;
	string p="110yyyyx10xxxxxx";
	r(i,16){
		if(p[i]=='y'&&(s[i]=='1'||s[i]=='x')) y=1;
		if(isdigit(p[i])&&isdigit(s[i])&&p[i]!=s[i])return 0;
	}
	if( !y )return 0;
	int dp[33][2]={};
	dp[0][0]=1;
	r(i,16){
		r(j,2){
			if(isdigit(p[i])){
				dp[i+1][j] += dp[i][j];
			}
			if(p[i]=='x'){
				int x=(isdigit(s[i])?1:2);
				dp[i+1][j] += dp[i][j]*x;
			}
			if(p[i]=='y'){
				if(s[i]=='1'){
					dp[i+1][1] += dp[i][j];
				}
				if(s[i]=='0'){
					dp[i+1][j] += dp[i][j];
				}
				if(s[i]=='x'){
					dp[i+1][1] += dp[i][j];
					dp[i+1][j] += dp[i][j];
				}
			}
			dp[i+1][j] %= 1000000;
		}
	}
	return dp[16][1];
}

int calc3(string s){
	int y=0;
	string p="1110yyyy10yxxxxx10xxxxxx";
	r(i,24){
		if(p[i]=='y'&&(s[i]=='1'||s[i]=='x')) y=1;
		//cout<<i<<endl;
		if(isdigit(p[i])&&isdigit(s[i])&&p[i]!=s[i])return 0;
	}
	//cout<<y<<endl;
	if( !y )return 0;
	int dp[33][2]={};
	dp[0][0]=1;
	r(i,24){
		r(j,2){
			if(isdigit(p[i])){
				dp[i+1][j] += dp[i][j];
			}
			if(p[i]=='x'){
				int x=(isdigit(s[i])?1:2);
				dp[i+1][j] += dp[i][j]*x;
			}
			if(p[i]=='y'){
				if(s[i]=='1'){
					dp[i+1][1] += dp[i][j];
				}
				if(s[i]=='0'){
					dp[i+1][j] += dp[i][j];
				}
				if(s[i]=='x'){
					dp[i+1][1] += dp[i][j];
					dp[i+1][j] += dp[i][j];
				}
			}
			dp[i+1][j] %= 1000000;
		}
	}
	return dp[24][1];
}

int calc4(string s){
	int y=0;
	string p="11110yyy10yyxxxx10xxxxxx10xxxxxx";
	r(i,32){
		if(p[i]=='y'&&(s[i]=='1'||s[i]=='x')) y=1;
		if(isdigit(p[i])&&isdigit(s[i])&&p[i]!=s[i])return 0;
	}
	if( !y )return 0;
	int dp[33][2]={};
	dp[0][0]=1;
	r(i,32){
		r(j,2){
			if(isdigit(p[i])){
				dp[i+1][j] += dp[i][j];
			}
			if(p[i]=='x'){
				int x=(isdigit(s[i])?1:2);
				dp[i+1][j] += dp[i][j]*x;
			}
			if(p[i]=='y'){
				if(s[i]=='1'){
					dp[i+1][1] += dp[i][j];
				}
				if(s[i]=='0'){
					dp[i+1][j] += dp[i][j];
				}
				if(s[i]=='x'){
					dp[i+1][1] += dp[i][j];
					dp[i+1][j] += dp[i][j];
				}
			}
			dp[i+1][j] %= 1000000;
		}
	}
	return dp[32][1];
}

int n;
string s[1111];
int dp[1111];

signed main(){
	while(cin>>n,n){
		r(i,n)cin>>s[i];
		memset(dp,0,sizeof(dp));
		dp[0] = 1;
		for(int i=0;i<n;i++){
			if( i+1 <= n ){
				int x = calc1(s[i]);
				dp[i+1] += dp[i]*x;
				dp[i+1] %= 1000000;
			}
			if( i+2 <= n ){
				int x = calc2(s[i]+s[i+1]);
				dp[i+2] += dp[i]*x;
				dp[i+2] %= 1000000;
			}
			if( i+3 <= n ){
				int x = calc3(s[i]+s[i+1]+s[i+2]);
				//cout<<x<<endl;
				dp[i+3] += dp[i]*x;
				dp[i+3] %= 1000000;
			}
			if( i+4 <= n ){
				int x = calc4(s[i]+s[i+1]+s[i+2]+s[i+3]);
				dp[i+4] += dp[i]*x;
				dp[i+4] %= 1000000;
			}
		}
		cout<<dp[n]<<endl;
	}
}
