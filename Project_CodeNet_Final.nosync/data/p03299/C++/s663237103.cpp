#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;

const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const long double EPS=1e-13;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
long long pw(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2)ret=ret*a%mod;
		a=a*a%mod;
		b/=2;
	}
	return ret;
}
long long dp[110][110];
long long dp2[110][110];

int p[110];
void solve(int a,int b,int c){
	if(dp[a][b]!=-1)return;
	if(a==b){
		int has=p[a]-c;
		dp[a][b]=0;
		dp2[a][b]=pw(2,has);
		return;
	}
	int mn=mod;
	for(int i=a;i<=b;i++){
		mn=min(mn,p[i]);
	}
	int left=a;
	vector<long long>d1;
	vector<long long>d2;
	int mc=0;
	for(int i=a;i<=b;i++){
		if(mn==p[i]){
			mc++;
			if(left<i){
				solve(left,i-1,mn);
				d1.push_back(dp[left][i-1]);
				d2.push_back(dp2[left][i-1]);
			}
			left=i+1;
		}
	}
	if(left<=b){
		solve(left,b,mn);
		d1.push_back(dp[left][b]);
		d2.push_back(dp2[left][b]);
	}
	long long ks2=1;
	for(int i=0;i<d2.size();i++)ks2=ks2*d2[i]%mod;
	dp2[a][b]=ks2*pw(2,mn-c)%mod;
	long long ks1=pw(2,mc);
	for(int i=0;i<d1.size();i++)ks1=ks1*(d1[i]+d2[i]*2)%mod;
	ks1=(ks1+mod*2-ks2*2)%mod;
	dp[a][b]=ks1;
}
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",p+i);
	for(int i=0;i<110;i++)for(int j=0;j<110;j++)dp[i][j]=-1;
	solve(0,a-1,0);
	printf("%lld\n",(dp[0][a-1]+dp2[0][a-1])%mod);
}