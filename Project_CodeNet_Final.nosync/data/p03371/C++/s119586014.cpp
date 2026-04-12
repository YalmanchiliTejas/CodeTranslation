#include <cmath>
#include <map>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
using namespace std;
const int MaxN = 1e5 + 4;
typedef long long LL;
map<int,int>mp;
pair<int,int> PLL;
int main(){
	int a,b,c,x,y;
	int ans = 1e9+5;
	cin>>a>>b>>c>>x>>y;
	if(2*c < a+b){
		int t = min(x,y);
		int v = max(x,y);
		int u = abs(x-y);
		if(x > y)
			ans = min(v*c*2,min(t*c*2+(x-y)*a,ans));
		else ans = min(v*c*2,min(t*c*2+(y-x)*b,ans));
	}
	else {
		ans = a*x+b*y;
	}
	cout<<ans<<endl;
	return 0;
}