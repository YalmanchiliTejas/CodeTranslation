//q005.cpp
//Sat Sep 19 16:30:44 2020

#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#define INTINF 2147483647
#define LLINF 9223372036854775807
#define MOD 1000000007
#define rep(i,n) for (int i=0;i<(n);++i)

using namespace std;
using ll=long long;
typedef pair<int,int> P;

int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;

	int ans = 0;
	ans += min(x,y)*min(a+b,2*c);
	if (x>y){
		ans += (x-y)*min(a,2*c);
	}else if (x<y){
		ans += (y-x)*min(b,2*c);
	}
	cout << ans << endl;
//	printf("%.4f\n",ans);
}