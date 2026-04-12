#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<set>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#define Max zhi5968
typedef long long ll;
using namespace std;

int main ()
{
	ll a,b,k,t;
	scanf("%lld %lld %lld",&k,&a,&b);
	if(k<=a)
	{
		cout<<"1"<<endl;
		return 0;
	}
	if(a<=b)
		printf("-1\n");
	else
	{
		t=(k-a)/(a-b);
		if((k-a)%(a-b)!=0)
			t++;
		printf("%lld\n",2*t+1);
	}
	return 0;
}