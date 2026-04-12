#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <map>
#include <numeric>
#include <set>
#include <iomanip>
#include <functional>
#define FOR(i, a, n) for (long long i = (a); i < (n); i++)
#define REP(i, n) for(long long i = 0; i < (n); i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define pb push_back
using namespace std;
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;

	if (A == B)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}