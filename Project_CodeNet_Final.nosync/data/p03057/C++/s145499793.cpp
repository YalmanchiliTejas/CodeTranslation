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
const long double EPS=1e-9;
const long double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long double ABS(long double a){return max(a,-a);}
char S[210000];
long long bit[210000];
long long sum(int a,int b){
	if(a)return (sum(0,b)-sum(0,a-1)+mod)%mod;
	long long ret=0;
	for(;b>=0;b=(b&(b+1))-1)ret+=bit[b];
	return ret%mod;
}
void add(int a,long long b){
	for(;a<210000;a|=a+1)bit[a]=(bit[a]+b)%mod;
}
long long dp[210000][2][2];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	scanf("%s",S);
	if(S[0]=='B'){
		for(int i=0;i<b;i++){
			if(S[i]=='B')S[i]='R';
			else S[i]='B';
		}
	}
	long long ret=0;
	int chk=0;
	for(int i=0;i<b;i++){
		if(S[i]=='B')chk=1;
	}
	if(chk==0){
		dp[1][0][0]=1;
		dp[1][1][1]=1;
		for(int i=1;i<a;i++){
			dp[i+1][0][0]=(dp[i+1][0][0]+dp[i][0][0]+dp[i][1][0])%mod;
			dp[i+1][1][0]=(dp[i+1][1][0]+dp[i][0][0])%mod;
			dp[i+1][0][1]=(dp[i+1][0][1]+dp[i][0][1]+dp[i][1][1])%mod;
			dp[i+1][1][1]=(dp[i+1][1][1]+dp[i][0][1])%mod;
			
		}
		ret=(dp[a][0][0]+dp[a][0][1]+dp[a][1][0])%mod;
		printf("%lld\n",ret);
		return 0;
	}
	if(a%2){
		printf("0\n");return 0;
	}
	bool wolf=true;
	int fi=0;
	int tmp=0;
	for(int i=0;i<b;i++){
		if(S[i]=='B'){
			if(wolf){
				fi=tmp;tmp=0;
				wolf=false;
			}else{
				if(tmp%2){
					fi=min(fi,tmp);
					//printf("2\n");return 0;
				}
				tmp=0;
			}
		}else{
			tmp++;
		}
	}
	a/=2;
	add(1,1);
	//if(fi%2)return 1;
	for(int i=2;i<=a;i++){
		int L;
		L=max(1,i-1-fi/2);
		long long tmp=sum(L,i-1);
		add(i,tmp);
	}
	for(int i=1;i<=a;i++){
	//	if(a-i>fi)continue;
		if(a-i>fi/2)continue;
	//	printf("%d: %lld\n",i,sum(i,i));
		ret=(ret+(a+1-i)*sum(i,i))%mod;
	}
	ret=ret*2%mod;
	printf("%lld\n",ret);
}