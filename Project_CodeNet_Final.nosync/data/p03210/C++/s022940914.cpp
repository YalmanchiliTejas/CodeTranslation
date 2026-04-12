#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int Min(int a, int b, int c) {
	if (a <= b) { return std::min(a, c); }
	else return std::min(b, c);
}
int main(void) {
	int a; cin >> a;
	if (a == 3 || a == 5 || a == 7)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}