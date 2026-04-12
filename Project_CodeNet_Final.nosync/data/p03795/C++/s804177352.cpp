#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	int ans;
	scanf("%d",&n);
	ans=n*800;
	n/=15;
	ans-=n*200;
	printf("%d\n",ans);
    return 0;
}
