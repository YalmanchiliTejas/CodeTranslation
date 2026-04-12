#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include<cassert>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<string>
#include<deque>
#include<queue>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<bitset>
#include<stack>
#include<iomanip>
#include<utility>
#include<functional>
using namespace std;
int n;
long long k;
long long l[55],m[55];
long long dfs(long long num,int d)
{
	long long ld=(l[d]+(long long)1)/(long long)2;
	if(d<0)
		return (long long)0;
	if(num==ld)
		return m[d-1]+(long long)1;
	if(num>ld)
		return m[d-1]+(long long)1+dfs(num-ld,d-1);
	if(num<ld)
		return dfs(num-1,d-1);
}
int main()
{	
	cin>>n>>k;
	l[0]=(long long)1;
	m[0]=(long long)1;
	for(int i=1;i<=n;i++)
	{
		l[i]=l[i-1]*(long long)2+(long long)3;
		m[i]=m[i-1]*(long long)2+(long long)1;
	}
	cout<<dfs(k,n);
	return 0;
}
