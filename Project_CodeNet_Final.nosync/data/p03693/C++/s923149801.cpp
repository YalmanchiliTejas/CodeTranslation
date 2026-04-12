#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	int res = a*100+b*10+c;
	if(res%4==0)printf("YES\n");
	else printf("NO\n");
}