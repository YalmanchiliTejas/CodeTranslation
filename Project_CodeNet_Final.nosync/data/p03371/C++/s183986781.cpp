#include <algorithm>
//#include <cstdio>
//#include <functional>
#include <iostream>
//#include <cfloat>
//#include <climits>
//#include <cstdlib>
//#include <cstring>
//#include <cmath>
//#include <map>
//#include <queue>
//#include <set>
//#include <sstream>
//#include <stack>
//#include <string>
//#include <time.h>
//#include <vector>
//#include <random>
//#include <unordered_set>
//#include <complex>
#define rt0 return 0
#define rep(i,n) for(int i=0;i<n;i++)
#define LL long long
using namespace std;
int main()
{
	LL a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	if(a+b<=c*2)
	{
		cout<<a*x+b*y;
		rt0;
	}
	LL mx=max(x,y),mn=min(x,y);
	LL ans1=mn*2*c,ans2=mx*2*c;
	if(mx==x) ans1+=(x-y)*a;
	else ans1+=(y-x)*b;
	cout<<min(ans1,ans2);
    rt0;
}