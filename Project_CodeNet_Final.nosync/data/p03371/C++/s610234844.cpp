#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<string>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;
int main(void){
	int a,b,c,x,y,ans1,ans2,ans3,ans;
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	ans1=a*x+b*y;
	if(x>y){
		ans2=c*y*2+a*(x-y);
		ans3=c*x*2;
	}else if(x<y){
		ans2=c*x*2+b*(y-x);
		ans3=c*y*2;
	}else{
		ans2=c*x*2;
		ans3=ans2;
	}
	ans=min(ans1,min(ans2,ans3));
	printf("%d\n",ans);
	return 0;
}