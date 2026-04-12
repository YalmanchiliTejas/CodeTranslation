#include<bits/stdc++.h>
using namespace std;
long long a,b,c,x,y,t1,t2,t3,ans;
int main()
{
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);
	t1=a*x+b*y;
	if(x<y) {
		t2=x*c*2+(y-x)*b;
		t3=y*c*2;
	}
	else{
		t2=y*c*2+(x-y)*a;
		t3=x*c*2;
	}
	ans=min(t1,t2);
	ans=min(ans,t3);
	printf("%lld\n",ans);
}