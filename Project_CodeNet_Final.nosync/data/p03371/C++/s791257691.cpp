#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<map>
#include<iomanip>
#define int long long
#define ll getchar();getchar();return 0;
using namespace std;
bool prime(int n) {
	int cnt = 0;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n%i == 0)cnt++;
	}
	if (cnt != 1)return false;
	else return n != 1;
}
int gcd(int x,int y) {
	int ans;
	for (int i = (min(x, y)); i >= 1; i--) {
		if (x%i == 0 && y%i == 0) {
			ans = i;
			break;
		}
	}
		return ans;
}
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}
int ketanowa(int n) {
	int cnt = 0, sum = 0;
	for (int i = 10; i <= n * 10; i *= 10) {
		if (i == 10)cnt += n % i;
		else sum += (n%i - n % (i / 10)) / (i / 10);
	}
	return cnt + sum;
}
signed main() {	
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	if(x>=y)cout << min({ c*max(x,y) * 2,a*x + b * y,c*min(x,y) * 2 + (x-y)*a }) << endl;
	else cout << min({ c*max(x,y) * 2,a*x + b * y,c*min(x,y) * 2 + (y-x)*b }) << endl;
	ll
}