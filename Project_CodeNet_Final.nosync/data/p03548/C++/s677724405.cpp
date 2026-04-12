//#pragma warning (disable:4996)
#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<stack>
#include<set>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
using ll = long long;

int  main() {
	ll X, Y, Z;
	cin >> X >> Y >> Z;
	cout << floor((X - Z) / (Y + Z)) << endl;
}
