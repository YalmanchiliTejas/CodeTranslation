
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <math.h>
#include <tuple>

#include <set>
#include <unordered_map>
#include <stack>

using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b < a) { a = b; return 1; } return 0; }
void YesNo(bool y) { cout << (y ? "Yes" : "No") << endl; }


#define INF 21474836

string S;

int main() {

	cin >> S;

	bool y = true;
	if (S == "AAA" || S == "BBB")y = false;

	YesNo(y);

	return 0;
}
