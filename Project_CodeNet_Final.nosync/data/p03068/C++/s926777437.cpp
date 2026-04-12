
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
#define lint long long
static const int INF = 1 << 22;
#define pii pair<long long,long long>
#define all(x) (x).begin(),(x).end()
/*******source code below********/
int main(void) {

	int n; cin >> n;
	string S; cin >> S;
	long long L; cin >> L;

	char a = S[L - 1];
	for (lint i = 0; i < S.size(); i++)
	{
		if (S.at(i) != a) S.at(i) = '*';
	}
	cout << S << endl;
	return 0;
}