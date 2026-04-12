#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int st[200001],d[200001],top,n;
int main()
{
	scanf("%d",&n);
	for(int i=n; i>=1; --i)
		scanf("%d",&d[i]);
	for(int i=1; i<=n; ++i) {
		if(d[i]>=st[top])
			st[++top]=d[i];
		else {
			int loc=upper_bound(st+1,st+top+1,d[i])-st;
			st[loc]=d[i];
		}
	}
	printf("%d",top);
	return 0;
}