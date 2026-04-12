#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[100005],b[100005];
int len;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	   cin>>a[i];

	b[1]=-a[1],len=1;

	for (int i=2;i<=n;i++)
		if (-a[i]>=b[len]) b[++len]=-a[i];
		else b[upper_bound(b+1,b+len,-a[i])-b]=-a[i];

	cout<<len<<endl;
}