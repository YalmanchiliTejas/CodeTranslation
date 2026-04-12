#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,cnt;
	scanf("%d%d%d",&a,&b,&c);
	cnt=a*100+b*10+c;
	if(cnt%4==0) printf("YES");
	else printf("NO");
	printf("\n");
    return 0;
}
