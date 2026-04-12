#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<bitset>
#include<vector>
#include<deque>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
#include<iomanip>
#include <functional>
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int INF = 1 << 28;
const double EPS = 1e-10;
//cout << fixed << std::setprecision(9)
//memset(a, 0, sizeof(a));
//--------------------------

char c;

int main()
{
	cin >> c;
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
		cout << "vowel" << endl;
	}
	else {
		cout << "consonant" << endl;
	}

	return 0;
}
