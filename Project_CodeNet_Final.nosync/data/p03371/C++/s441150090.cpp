#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int ans[5];
int main()
{
	int a,b,c,x,y;
	while(scanf("%d%d%d%d%d",&a,&b,&c,&x,&y)!=EOF){
		ans[1] = a*x+b*y;
		if(x>y){
			ans[2] = a*(x-y)+2*c*y;
		}
		else{
			ans[2] = b*(y-x)+2*c*x;
		}
		ans[3] = 2*c*(max(x,y));
		int minx = ans[1];
		for(int i=2;i<=3;++i){
			if(ans[i]<minx)
				minx = ans[i];
		}
		cout<<minx<<endl;
	}
	return 0;
}