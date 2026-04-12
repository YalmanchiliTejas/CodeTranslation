#include <algorithm>
//#include <cstdio>
//#include <functional>
//#include <bits/stdc++.h>
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
#include <string>
//#include <time.h>
//#include <vector>
//#include <random>
//#include <unordered_set>
//#include <complex>
#define rt0 return 0
using namespace std;
 
int main()
{
	int a,b,c,x,y;
	int temp;

	cin>>a>>b>>c>>x>>y;

	int ans=min((a*x+b*y),(c*2*max(x,y)));
	if(x>y) temp=a*(x-y);
	else temp=b*(y-x);
	ans=min(c*2*min(x,y)+temp, ans);
		
	cout<<ans;
    rt0;
}
