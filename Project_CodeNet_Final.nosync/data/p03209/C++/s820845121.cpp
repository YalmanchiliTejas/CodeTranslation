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
long long V[60];
long long B[60];
long long calc(int a,long long b){
	long long ret=0;
	b--;
	if(b==0)return ret;
	if(b>=V[a-1]){
		b-=V[a-1];
		ret+=B[a-1];
	}else{
		ret+=calc(a-1,b);
		return ret;
	}
	if(b==0)return ret;
	ret++;b--;
	if(b==0)return ret;
	if(b>=V[a-1]){
		b-=V[a-1];
		ret+=B[a-1];
	}else{
		ret+=calc(a-1,b);
		return ret;
	}
	return ret;
}
int main(){
	int a;
	V[0]=1;
	B[0]=1;
	for(int i=1;i<55;i++)V[i]=V[i-1]*2+3;
	for(int i=1;i<55;i++)B[i]=B[i-1]*2+1;
	long long b;scanf("%d%lld",&a,&b);
	printf("%lld\n",calc(a,b));
}