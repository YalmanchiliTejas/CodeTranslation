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
int p[110000];
long long L[110000];
long long R[110000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d",p+i);
	}
	long long ret=0;
	for(int i=1;i<a;i++){
		long long cur=0;
		for(int j=0;j<a;j+=i){
			cur+=p[j];
			L[j]=cur;
		}
		cur=0;
		for(int j=a-1;j>=0;j-=i){
			cur+=p[j];
			R[j]=cur;
		}
		int left=0;
		int right=a-1;

		while(left<a-1){
			ret=max(ret,L[left]+R[right]);
			left+=i;
			right-=i;
			if(right<=i)break;
			if(left>=right&&left%i==right%i)break;
		}
	}
	printf("%lld\n",ret);
}
