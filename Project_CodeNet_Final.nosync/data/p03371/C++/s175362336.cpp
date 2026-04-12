#include<bits/stdc++.h>

using namespace std;

string s;
int n,m,minn=0x3f3f3f3f,ans,sum,a,b,c,x,y;

int main(){
	scanf("%d%d%d%d%d",&a,&b,&c,&x,&y);
	if(c*2<a+b) {
		int tt=min(x,y);
		ans+=tt*2*c;
		x-=tt,y-=tt;	
	}
	a=min(a,2*c),b=min(b,2*c);
	ans+=x*a+y*b;
	printf("%d",ans);
	return 0;	
}