#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define repr(i,n) for(int i=n-1;i>=0;i--)
#define MAX(a,b) a=a>b?a:b
#define MIN(a,b) a=a>b?a:b
#define REP(i,x,n) for(int i=x;i<n;i++)
#define REPR(i,x,n) for(int i=n-1;i>=x;i--)
#define F first
#define S second
using namespace std;
typedef long long ll;
ll wa=1000000007;



ll dp[10101][2][101]={};



int main(){
	string s;
   	int n;
	cin>>s>>n;
	rep(i,s[0]-'0')dp[0][0][i%n]++;
	dp[0][1][(s[0]-'0')%n]++;
	REP(i,1,s.size()){
		rep(j,n){
			rep(k,10){
				dp[i][0][(j+k)%n]+=dp[i-1][0][j];
				dp[i][0][(j+k)%n]%=wa;
				
			}
			rep(k,(int)s[i]-'0'+1){
				if(k==(int)s[i]-'0'){
					dp[i][1][(j+k)%n]+=dp[i-1][1][j];
					dp[i][1][(j+k)%n]%=wa;
				}else{
					dp[i][0][(j+k)%n]+=dp[i-1][1][j];
					dp[i][0][(j+k)%n]%=wa;
				}
			}
		}
	}
	

	if(dp[s.size()-1][0][0]==0){dp[s.size()-1][0][0]=wa;}
	cout<<(dp[s.size()-1][1][0]+dp[s.size()-1][0][0]-1)%wa<<endl;
}

