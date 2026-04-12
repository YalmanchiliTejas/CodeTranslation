#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;


int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	bool ans = (a*100 + b*10 + c)%4;
	if(ans) printf("NO\n");
	else printf("YES\n");	
	return 0;
}