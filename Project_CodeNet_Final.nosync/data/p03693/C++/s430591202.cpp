#include <bits/stdc++.h>
using namespace std;

int main(){
	int a[3];
	for(int i = 0;i < 3;i++)scanf("%d", &a[i]);
	int x = a[0]*100+a[1]*10+a[2];
	if(x % 4 == 0)printf("YES\n");
	else printf("NO\n");
	return 0;
}