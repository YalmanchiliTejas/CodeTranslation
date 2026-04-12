#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int a, b, h, c, d;
	cin >> a >> b >> h >> c >> d;
	int ans;
	if (c >= d) ans = d * h * 2 + (c - d)*a;
	else ans = c * h * 2 + (d - c)*b;

	int aans;
	if (c >= d) aans = c * 2 * h;
	else aans = d * 2 * h;
	int bans = min(aans, ans);
	cout << min(a*c + b * d, bans) << endl;
}