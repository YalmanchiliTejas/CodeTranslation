#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<vector>
#include<cctype>
using namespace std;
signed main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	puts(((((a*100)+(b*10)+c)%4)?("NO"):("YES")));
	return 0;
}