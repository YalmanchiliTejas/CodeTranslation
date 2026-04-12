#include<iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <math.h>
#include <stack>
#include <cctype>
using namespace std;
#define int long long
#define pi 2*acos(0.0)
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define REP(i,n) for (int i=0;i<(n);i++)

signed main()
{
	char a;
	cin >> a;
	if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a == 'o') cout << "vowel" << endl;
	else cout << "consonant" << endl;
}
