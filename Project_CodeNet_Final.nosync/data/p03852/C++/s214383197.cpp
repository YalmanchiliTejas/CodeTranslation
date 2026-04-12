#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
#include <queue>
#include <stack>
#include <deque>
#include <functional>
#define rep(i,n) for(int i=0;i<n;i++)
#define FOR(i,s) for(int i=s;i>=0;i--)

using ll = long long;
using namespace std;

const ll INF = 1010101010;
const ll MOD = 1000000007;

int main() {
	ll n, m, ans = 0, A[10101];
	char c;
	cin >> c;
	if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o')
		cout << "vowel" << endl;
	else
		cout << "consonant" << endl;
	return 0;
}
