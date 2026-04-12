#include<bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define all(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;
using vint = vector<int>;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int a, b, c, x, y, r = 0;
	cin >> a >> b >> c >> x >> y;
	if (a + b <= c*2){
		cout << a*x + b*y << "\n";
		return 0;
	}
	int m = min(x, y);
	r += c * (m * 2);
	x -= m;
	y -= m;
	if (x > 0){
		if (a/2 < c){
			r += a*x;
		}else{
			r += c*x*2;
		}
	}
	if (y > 0){
		if (b/2 < c){
			r += b*y;
		}else{
			r += c*y*2;
		}
	}
	cout << r << "\n";
	return 0;
}