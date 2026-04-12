//ΔARC 095A
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int a[N],b[N];
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i),b[i]=a[i];
	sort(b+1,b+n+1);
	for(i=1;i<=n;i=i+1){
		if(a[i]<=b[n/2])
			printf("%d\n",b[n/2+1]);
		else
			printf("%d\n",b[n/2]);
	}
	return 0;
}