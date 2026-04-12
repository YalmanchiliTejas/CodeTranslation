#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
#define mod 1000000007
#define ALL(a) a.begin(),a.end()
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
 
int main(){
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;

	int ans = 0;
	if (a+b > c*2){
		ans += min(x, y) * c * 2;
		if (x > y){
			ans += min((x - y) * c * 2, (x - y) * a); 
		}else{
			ans += min((y - x) * c * 2, (y - x) * b);
		}
	}else{
		ans += x * a + y * b;
	}
	cout << ans << endl;
	return 0;
}