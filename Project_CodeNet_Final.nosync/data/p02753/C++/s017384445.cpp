#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>
#include <time.h>
#include <bitset>

using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }

char S[5];

int main() {

	cin >> S;

	if (S[0] == S[1] && S[1] == S[2]) cout << "No" << endl;

	else cout << "Yes" << endl;

	return 0;
}
