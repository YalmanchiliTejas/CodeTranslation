#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
const ll mod = 1e9 + 7;
const int INF = 1e9;

int main() {
	cin.sync_with_stdio(false);
	int X, Y, Z;
	cin >> X >> Y >> Z;
	cout << X / (Y + Z) - (X % (Y + Z) >= Z ? 0 : 1) << endl;
	return 0;
}