#include<iostream>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i=0;i<(int)n;i++)

int main(void) {
	int a, b, c; cin >> a >> b >> c;
	int res = a * 100 + b * 10 + c;
	cout << (res % 4 == 0 ? "YES" : "NO") << endl;
	return 0;
}