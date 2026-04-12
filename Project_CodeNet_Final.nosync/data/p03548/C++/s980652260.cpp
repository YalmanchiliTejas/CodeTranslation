#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

int main(){
	int x = 0,y = 0,z = 0;
	int ans = 0;
	scanf("%d %d %d",&x,&y,&z);
	ans = x/(z + y);
	if(x - ans*(y + z) >= 0&&x - ans*(y + z) < z){ 
		ans = ans - 1;
		printf("%d\n",ans);
	}
	else printf("%d\n",ans);
	return 0;
	}