#include<iostream>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<tuple>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;



int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int X, Y, Z;
	cin >> X >> Y >> Z;
	X -= Z;
	cout << X / (Y + Z) << "\n";

	return 0;
}