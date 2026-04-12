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

	if (c*2>=a+b){
		cout << a*x + b*y << endl;
	}else {
		int ans = min(x,y)*2*c;
		if (x>y && a<=2*c){
			ans += (x-y)*a;
		}else if (x>y){
			ans += (x-y)*c*2;
		}else if (x<y && b<=2*c){
			ans += (y-x)*b;
		}else if (x<y){
			ans += (y-x)*c*2;
		}
		cout << ans << endl;
	}

//	printf("%.4f\n",ans);
}