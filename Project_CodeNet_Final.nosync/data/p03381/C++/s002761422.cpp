#include<algorithm>
#include<clocale>
#include<cmath>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<iostream>
#include<istream>
#include<map>
#include<math.h>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int n,a[200010],b[200010];
int main()
{
	cin>>n;
	for (int i=0;i<n;i++) cin>>a[i];
	for (int i=0;i<n;i++) b[i]=a[i];
	sort(b,b+n);
	for (int i=0;i<=n/2;i++)
		if (a[i]==b[n/2])
			cout<<b[n/2-1]<<endl;
		else if (a[i]<b[n/2])
			cout<<b[n/2]<<endl;
		else if (a[i]>b[n/2])
			cout<<b[n/2-1]<<endl;
	for (int i=n/2+1;i<n;i++)
		if (a[i]==b[n/2])
			cout<<b[n/2-1]<<endl;
		else if (a[i]<b[n/2])
			cout<<b[n/2]<<endl;
		else if (a[i]>b[n/2])
			cout<<b[n/2-1]<<endl;
	return 0;
}