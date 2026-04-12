#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;
struct node
{
	int id;
	int num;
} a[N];
int b[N];
bool cmp(node x,node y)
{
	return x.num < y.num;
}
int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
	{
		scanf("%d",&a[i].num);
		a[i].id = i;
	} 
	sort(a,a+n,cmp);
	for (int i = 0;i < n;i++)
	{
		int id = a[i].id;
		if (i >= n / 2) b[id] = a[n/2-1].num;
		else b[id] = a[n/2].num;
	}
	for (int i = 0;i < n;i++) printf("%d\n",b[i]);
	return 0;
}