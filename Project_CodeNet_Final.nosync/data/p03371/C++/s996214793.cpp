#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main()
{
	int a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	int q, r;
	int s, t;
	if (x >= y) {
		q = x;
		r = y;
		s = a;
		t = b;
	}
	else if (x < y) {
		q = y;
		r = x;
		s = b;
		t = a;
	}
	vector<int> v;
	v.push_back(s * q + t * r);
	v.push_back(s * (q - r) + c * 2 * r);
	v.push_back(2 * q * c);
	sort(v.begin(), v.end());
	cout << v[0];
}
