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
int n;
signed main()
{
	scanf("%d",&n);
	printf("%d",((n*800)-((n/15)*200)));
	return putchar(10),0;
}