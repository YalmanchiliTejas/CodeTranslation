#include <iostream>
#include <vector>
#include <iomanip>
#include <stack>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <iterator>
#include <string>
#include <cstring>
//#include <fstream>
#include <complex>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define REP(i,n) for(int i=0;i<(n);i++)
#define RREP(i,n) for(int i=n;i>0;i--)
#define arep(a,i,n) for(int i=(a);i<(n);i++)
#define SORT(v) sort((v).begin(),(v).end())
const ll INF = (1LL << 50);
typedef pair<int, int> P;

int main() {

	string s;
	cin >> s;

	if (s[0] == 'A' &&s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
	else if (s[0] == 'B' &&s[0] == s[1] && s[1] == s[2]) cout << "No" << endl;
	else cout << "Yes" << endl;

	return 0;

}