#pragma comment(linker,"/STACK:102400000,102400000")
#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cctype>
#include <climits>
#include <cmath>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
using namespace std;


int main(){	
	int A,B,C,X,Y;
	int x1,x2,x3,ans=0x3f3f3f3f;
	scanf("%d %d %d %d %d",&A,&B,&C,&X,&Y);
	int maxm=max(X,Y); 
	for(int i=0;i/2<=maxm;i+=2){
		x1=X-i/2,x2=Y-i/2;
		x1=x1<0?0:x1;
		x2=x2<0?0:x2;
		ans=min(ans,x1*A+x2*B+i*C);
	}
	printf("%d\n",ans);
	return 0;
}
