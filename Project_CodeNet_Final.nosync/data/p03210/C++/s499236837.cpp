#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#define rep(i,n) for(int i =0;i<(int)(n);i++)
typedef long long ll;
using namespace std;
int main() {
	int x;
	cin >> x;
	if (x == 7 || x == 5 || x == 3) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}
