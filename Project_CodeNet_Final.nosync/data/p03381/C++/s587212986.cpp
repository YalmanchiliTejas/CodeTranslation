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
int b[210000];
pair<int,int> z[210000];
int ans[210000];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)scanf("%d",b+i);
	for(int i=0;i<a;i++){z[i]=make_pair(b[i],i);}
	std::sort(z,z+a);
	for(int i=0;i<a;i++){
		if(i<a/2)ans[z[i].second]=z[a/2].first;
		else ans[z[i].second]=z[a/2-1].first;
	}
	for(int i=0;i<a;i++)printf("%d\n",ans[i]);
}
