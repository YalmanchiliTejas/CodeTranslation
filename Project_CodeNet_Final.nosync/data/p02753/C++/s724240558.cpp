#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <limits>
#include <numeric>
#include <set>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<char> vc;

#define PI 3.14159265359
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repz(i,n) rep(i,0,n)


int main() {
	vc s(3);
	cin >> s[0] >> s[1] >> s[2];
	sort(s.begin(), s.end());
	if (s[0] == s[2])cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;
}