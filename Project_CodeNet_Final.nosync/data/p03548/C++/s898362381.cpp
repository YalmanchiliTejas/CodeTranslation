#include <iostream>
#include <algorithm>

using namespace std;
typedef long long  ll;
#define rep(i,s,n)for(ll i = s;i<n;i++)

int main() {
	int X, Y, Z; cin >> X >> Y >> Z;
	cout << (X - Z) / (Z + Y) << endl;
}