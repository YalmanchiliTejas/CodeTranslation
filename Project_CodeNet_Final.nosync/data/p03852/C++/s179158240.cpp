#pragma region Template
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

#define EPS 1e-14
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) FOR(i, 0, n)
#define PI 2*acos(0.0)
#define ALL(a) (a).begin(),(a).end()
#define DEBUG(x) cout<<#x <<": "<< x << "\n"
#define DEBUG_ARR(a) REP(i, size(a)){ cout << #a << "[" << i << "]: " << a[i] << "\n"; }
const int VX[] = { 0, 1, 0, -1 };
const int VY[] = { 1, 0, -1, 0 };
const long MOD = 1000000007;

#pragma endregion

int main()
{
	//	--- I/O 高速化 ---
	cin.tie(0);
	ios::sync_with_stdio(false);
	// --- ここまで ---

	char c;
	char d[]= { 'a', 'e', 'i', 'o', 'u' };

	cin >> c;

	for (int i = 0; i < 5; i++)
	{
		if (c == d[i])
		{
			cout << "vowel\n";
			return 0;
		}
	}

	cout << "consonant\n";
	return 0;
}

