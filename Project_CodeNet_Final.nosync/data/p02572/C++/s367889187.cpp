#include<cstdio>
//#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
const int maxv = 200005;
const int inf = 1e9 + 7;
int ar[maxv];
int main(){
	int n;
	ll sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&ar[i]);
		sum+=ar[i];
		sum%=inf;
	} 
	ll ans=0;
	for(int i=1;i<=n;i++){
		sum-=ar[i];
		if(sum<0) sum+=inf;
		ans+=ar[i]*sum;
		ans%=inf;
	}
	printf("%lld\n",ans);
	return 0;
}
