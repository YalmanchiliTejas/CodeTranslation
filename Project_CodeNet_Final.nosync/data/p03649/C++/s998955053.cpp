#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
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
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
long long p[60];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%lld",p+i);
	std::sort(p,p+a);
	reverse(p,p+a);
	long long ret=0;
	for(int i=0;i<a-1;i++){
		long long dif=p[0]-p[i+1];
		long long ks=dif/(a+1);
		//printf("%d: %lld %lld\n",i,dif,ks);
		ret+=ks*(i+1);
		for(int j=0;j<a;j++){
			if(j<=i){
				p[j]-=ks*a-ks*i;
			}else{
				p[j]+=ks*(i+1);
			}
		}
		//printf("%lld ",ret);
		for(int j=0;j<=i;j++){
			if(p[j]<a||p[j]<=p[i+1])break;
			p[j]-=a+1;
			for(int k=0;k<a;k++)p[k]++;
			ret++;
		}
		//printf("%lld\n",ret);
		std::sort(p,p+a);
		reverse(p,p+a);
		//for(int j=0;j<a;j++)printf("%lld ",p[j]);printf("\n");
	}
	long long ks=p[a-1]-a+1;
	if(ks>0){
		ret+=ks*a;
		for(int j=0;j<a;j++){
			p[j]-=ks;
		}
	}
	while(1){
		std::sort(p,p+a);reverse(p,p+a);
		if(p[0]<a)break;
		p[0]-=a;for(int i=1;i<a;i++)p[i]++;ret++;
	}
	printf("%lld\n",ret);
}