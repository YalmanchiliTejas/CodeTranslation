#include <bits/stdc++.h>
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define PI 3.141592653589793238462643383279502884L
#define lli long long int
#define d double
#define mod 1000000007
#define mx 200001
using namespace std;
void add_me(lli &a,lli b){
	a+=b;
	if(a>=mod) a-=mod;
}
void sub_me(lli &a,lli b){
	a-=b;
	if(a<0) a+=mod;
}
int main() {
	FIO;
	string K;
	int D;
	cin>>K;
	cin>>D;
	int n=K.length();
	vector<vector<lli>> dp(D,vector<lli>(2));
	//dp[i][j]->total ways to get remainder i with condition j(T/F)....
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		vector<vector<lli>> temp_dp(D,vector<lli>(2));
		for(int j=0;j<D;j++){
			for(bool is_smaller : {false,true}){
				for(int k=0;k<10;k++){
					if(k>K[i]-'0' && !is_smaller) break;
					add_me(temp_dp[(j+k)%D][is_smaller||k<(K[i]-'0')],dp[j][is_smaller]);
				}
			}
		}
		dp=temp_dp;
	}
	lli ans=(dp[0][0]+dp[0][1])%mod;
	sub_me(ans,1);
	cout<<ans<<endl;
}