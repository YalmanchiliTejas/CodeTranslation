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
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int x[210000];
int y[210000];
int cnt[210000];
pair<int,int>ev[410000];
int main(){
	int a;scanf("%d",&a);
	int xl=mod;
	int xr=0;
	int yl=mod;
	int yr=0;
	for(int i=0;i<a;i++){
		scanf("%d%d",x+i,y+i);
		if(x[i]>y[i])swap(x[i],y[i]);
		xl=min(xl,x[i]);
		xr=max(xr,x[i]);
		yl=min(yl,y[i]);
		yr=max(yr,y[i]);
		ev[i*2]=make_pair(x[i],i);
		ev[i*2+1]=make_pair(y[i],i);
	}
	std:;sort(ev,ev+a*2);

	long long ret=(long long)(xr-xl)*(yr-yl);
	//ret=min(ret,(long long)(yr-xl)*ABS(yl-xr));
	int left=0;
	int z=a;
	for(int i=0;i<a*2;i++){
		if(cnt[ev[i].second]==0)z--;
		cnt[ev[i].second]++;
		while(z==0){
			ret=min(ret,(long long)(yr-xl)*(ev[i].first-ev[left].first));
			cnt[ev[left].second]--;
			if(cnt[ev[left].second]==0)z++;
			left++;
		}
	}
	printf("%lld\n",ret);
}