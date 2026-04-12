#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll oo=1e18;
struct data{
	ll x,y;
}b[200005];
bool cmp(data a,data c) { return a.x<c.x; }//按照x排序 
ll ans=oo,n;
ll max1,max2;
ll min1=oo,min2=oo;//1为较小的，2为较大的
int main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&b[i].x,&b[i].y);
		if(b[i].x>b[i].y) swap(b[i].x,b[i].y);//保证x较小 
		max1=max(b[i].x,max1);	max2=max(b[i].y,max2);
		min1=min(b[i].x,min1);	min2=min(b[i].y,min2);
	}
	ans=(max1-min1)*(max2-min2);
	sort(b+1,b+n+1,cmp);
	ll big=max(b[1].y,b[n].x),sma=min(b[1].y,b[2].x);//维护另一序列中的最大最小值 
	ll tmp=big-sma;sma=b[1].y;
	for(int i=2;i<n;i++){
		big=max(big,b[i].y);
		sma=min(sma,b[i].y);
		tmp=min(tmp,big-min(sma,b[i+1].x));
	}
	ans=min(ans,tmp*(max2-min1));//已将最大值和最小值挤在一坨 
	printf("%lld\n",ans);
	return 0;
}