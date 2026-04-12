#include <iostream>
using namespace std;
typedef long long ll;
#define rep(i,s,n)for(int i = s;i<n;i++)
#define repe(i,s,n)for(int i = s;i<=n;i++)

int main() {
	int X, Y, Z; cin >> X >> Y >> Z;
	cout << (X - 2 * Z - Y) / (Y + Z) + 1 << endl;
	return 0;
}