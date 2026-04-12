#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#define rep(i,n) for(int i =0;i<(int)(n);i++)
typedef long long ll;
using namespace std;
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if ((100 * a + 10 * b + c) % 4 == 0) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
