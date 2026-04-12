#include<cstdio>
#include<algorithm>
#include<queue>
#include<cstring>
#include<bitset>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<stdint.h>
#include<set>
#include<stack>
#include<cmath>
#include<cstring>
#include<vector>
#include<iomanip>
#include<iostream>
#include<ctime>
using namespace std;
long long n,k,i,res;
int main()
{
	cin>>n>>k;
	if (!k) return cout<<n*n<<endl,0;
	for (i=k+1;i<=n;i++)
	{
		if (n%i>=k) res+=n%i-k+1;
		res+=n/i*(i-k);
	}
	cout<<res<<endl;
	return 0; 
}