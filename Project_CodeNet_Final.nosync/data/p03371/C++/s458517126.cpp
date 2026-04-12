#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
int GCD(int a,int b){return b?GCD(b,a%b):a;}
int LCM(int a,int b){return (a*b)/GCD(a,b);}
int abs(int x){return x>0?x:-x;}
 
//const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
//const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main()
{
	int a, b, c, x, y;
	ll ans = 0;
	cin >> a >> b >> c >> x >> y;

	if (a + b > c * 2){
		if (x < y){
			ans += x * 2 * c;
			y -= x;
			x = 0;
		}
		else {
			ans += y * 2 * c;
			x -= y;
			y = 0;
		}
	}

	if (x){
		if (a > c*2){
			ans += x * 2 * c;
			x = 0;
		}
		else {
			ans += x * a;
			x = 0;
		}
	}
	
	if (y){
		if (b > c*2){
			ans += y * 2 * c;
			y = 0;
		}
		else {
			ans += y * b;
			y = 0;
		}
	}

	cout << ans << endl;




}
