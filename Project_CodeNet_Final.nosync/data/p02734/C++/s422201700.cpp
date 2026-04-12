/*
AuThOr GaRyMr
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int n,a[3003],s;
const int MOD=998244353;
LL dp[3003][3003];
int main(){
	fastio;
	cin>>n>>s;
	LL res=0;
	rb(i,1,n){
		cin>>a[i];
		rb(j,0,s){
			dp[i][j]+=dp[i-1][j];
			if(j+a[i]<s){
				if(j==0){;
					dp[i][j+a[i]]+=i;
					dp[i][j+a[i]]%=MOD;
				}
				else{
					dp[i][j+a[i]]+=dp[i-1][j];
					dp[i][j+a[i]]%=MOD;
				}
			}
			else{
				if(j+a[i]==s){
					if(j==0){
						res+=(LL)(i)*(n-i+1);
						res%=MOD;
					}	
					else{
						res+=dp[i-1][j]*(n-i+1);
						res%=MOD;
					}
				}
			}
		}
	} 
	cout<<res<<endl;
	return 0;
}
