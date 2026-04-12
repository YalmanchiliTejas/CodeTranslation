#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<utility>//swapでaとbの値を入れ替える
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define s(s) sort(s.begin(),s.end())
#define r(s) reverse(s.begin(),s.end())
using namespace std;
int main() {
	int a, b, c, x, y, abc = 0, agc = 0; 
	ll ans = 0,arc=0;
	cin >> a >> b >> c >> x >> y;
	if (a + b <= c * 2)ans = a * x + b * y;
	else {
		abc = min(x, y);
		agc = max(x, y);
		ans += c * 2 * abc;
		if (x > y)ans += a * (agc - abc);
		else ans += b * (agc - abc);
	arc = c*2 * agc;
	ans = min(arc, ans);
    }
	cout << ans << endl;
	return 0;
}

