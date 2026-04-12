#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<map>
#include<set>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<fstream>
#include<sstream>
#include<cassert>
#include<iomanip>
#include<utility>
#include<bitset>
using namespace std;
int a[200010];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n%2)
	{
		for(int i=0;i<=n/2;i++)
		cout<<a[n-i*2]<<" ";
		for(int i=1;i<=n/2-1;i++)
		cout<<a[i*2]<<" ";
		if(n!=1)
		cout<<a[n-1];
	}
	else
	{
		for(int i=0;i<n/2;i++)
		cout<<a[n-i*2]<<" ";
		for(int i=0;i<n/2-1;i++)
		cout<<a[i*2+1]<<" ";
		cout<<a[n-1]; 
	}
	return 0;
}