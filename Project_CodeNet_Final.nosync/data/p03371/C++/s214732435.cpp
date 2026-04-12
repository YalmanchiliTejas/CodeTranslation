#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#define MIN 1<<31-1
#define HMAX 1000000000000000000
#define MOD 1000000007
#define REP(i,n) for(int i = 0; i < (n); i++)
#define RSET(s) for(set<int>::iterator it=s.begin();it!=s.end();it++)
typedef long long int ll;
using namespace std;
int main()
{
	ll a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if(c>(a+b)/2)
		cout<<d*a+e*b;
	else
	{
		int C;
		if(d>e)
		{
			swap(d,e);
			swap(a,b); 
		}
		C=d;
		d-=C;e-=C;
		if(b<2*c)
		cout<<C*2*c+e*b;
		else
		cout<<C*2*c+2*c*e;
	}
}