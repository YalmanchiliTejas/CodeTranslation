#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define lld long long
#define llu unsigned long long

using namespace std;
int main()
{
	lld i,k,n,s,t;
	scanf("%lld%lld",&n,&k);
	s=0;
	for(i=k+1;i<=n;i++)
	{
		t=(n%i-k+1);
		//cout<<t<<endl;
		s+=(n/i)*(i-k);
		if(t>0)
			s+=t;
	}
	if(k==0)
		s=n*n;
	printf("%lld\n",s);
	return 0;
}