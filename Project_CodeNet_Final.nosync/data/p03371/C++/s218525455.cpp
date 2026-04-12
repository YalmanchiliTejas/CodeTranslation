#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<numeric>
#include<set>
#include<iomanip>
#include<map>
#include<type_traits>
#include<tuple>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;


int main(){
	double a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	double value = (a + b) / 2;
	ll ans = 0;
	if(value > c)	ans += min(x, y) * c * 2;
	else ans += min(x, y) * a + min(x, y) * b;
	
	ll extra = max(x, y) - min(x, y);
	if(x >= y){
		if(a <= c * 2) ans += extra * a;
		else ans += extra * c * 2;
	} else {
		if(b <= c * 2) ans += extra * b;
		else ans += extra * c * 2;
	}

	cout << ans << endl;

}