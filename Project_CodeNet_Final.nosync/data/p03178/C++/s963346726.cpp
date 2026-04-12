#include<bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define VAL 100000
#define ll long long
#define INF 10000000000000000LL
#define pll pair<long long , long long>
const int MAX=1e4+10;
const ll MOD=1e9+7;
const int TOT_PRIMES=19;
const int MAX_A=70;
using namespace std;
int D;
ll dp[MAX][300][3];
int n;
string K;
bool vis[MAX][300][3];

int main() 
{ 
	//ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);	
//	#ifndef ONLINE_JUDGE
//	freopen("inp.txt" ,"r", stdin );
//	freopen("out.txt", "w", stdout);
//	#endif
	cin>>K;
	cin>>D;
	n=K.size();
	dp[0][0][0]=1;
	for(int i=0;i<n;i++){
		int a=K[i]-'0';
		for(int j=0;j<D;j++){
			for(int x=0;x<10;x++){
				dp[i+1][(j+x)%D][1]+=dp[i][j][1];
				if(x==a){
					dp[i+1][(j+x)%D][0]+=dp[i][j][0];
				}
				else if(x<a){
					dp[i+1][(j+x)%D][1]+=dp[i][j][0];
				}
				dp[i+1][(j+x)%D][0]%=MOD;
				dp[i+1][(j+x)%D][1]%=MOD;
			}
		}
	}
	cout<<(dp[n][0][0]+dp[n][0][1]-1+MOD)%MOD;
	
}