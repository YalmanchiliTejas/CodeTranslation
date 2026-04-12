#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>

#define rep(i, n) for(int i=0;i<n;i++)

using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;

	int ans = a * 100 + b * 10 + c;
	if (ans % 4 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;


	return 0;
}