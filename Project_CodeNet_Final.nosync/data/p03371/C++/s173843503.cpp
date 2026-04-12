#include <iostream>
#include <cstdio>
#include <bitset>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;
using ll=long long;
using vint=vector<int>;
using pint=pair<int,int>;

const double EPS = 1e-9;
const int inf = numeric_limits<int>::max();

#define rep(i,n) for(int i=0;i<int(n);++i)
#define rrep(i,n) for(int i=int(n-1);i>=0;--i)
#define REP(i,a,b) for(int i=int(a);i<int(b);++i)
#define RREP(i,a,b) for(int i=int(b-1);i>=int(a);--i)
#define SHOW(a) cout << #a << " = " << a << endl
#define ARR(a,n) for(int i=0;i<int(n);++i) cout << #a << "[" << i << "]" << " = " << a[i] << endl

void solve(){
	int A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	if((A + B) / 2 < C){
		cout << A * X + B * Y << endl;
	}else{
		int ans = 0;
		int c = min(X,Y);
		ans += c * 2 * C;
		if(X>c){
			if(2*C < A){
				ans += 2 * C * (X - c);
			}else{
				ans += A * (X - c);
			}
		}
		if(Y>c){
			if(2*C < B){
				ans += 2 * C * (Y - c);
			}else{
				ans += B * (Y - c);
			}
		}
		cout << ans << endl;
	}

}

int main(){
	solve();
	return 0;
}