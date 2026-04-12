//q5.cpp
//Sat Aug  8 09:48:45 2020

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

	int ans = INTINF;
	rep(i,max(x,y)*2+1){
		int cost = 2*c*i;
		if (x-i>0){
			cost += (x-i)*a;
		}
		if (y-i>0){
			cost += (y-i)*b;
		}
		ans = min(ans,cost);
	}

	cout << ans << endl;

//	printf("%.4f\n",ans);
}