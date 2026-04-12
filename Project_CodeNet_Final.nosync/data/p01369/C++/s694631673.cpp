#ifndef _WIN32
#include<iostream>
#endif // !_WIN32

#include<string>
#include<cmath>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;
string r = "yuiophjklnm";

#define ITR(x,v) for(auto &x:v)
int f(char c) {
	ITR(cc, r)if (c == cc)return 1;
	return 0;

}
int main() {
	string s;
	while (cin >> s, s != "#") {
		vector<int> v;
		ITR(c, s)v.push_back(f(c));

		int prv = v.front();
		int res = 0;
		ITR(x, v) {
			res += (prv != x);
			prv = x;
		}
		cout << res << endl;
	}

	return 0;
}