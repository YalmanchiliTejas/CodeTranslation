#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctype.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <cctype>
#include <queue>
#include <set>
#include <list>
#define PI 3.141592653
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define DescSort(a) sort(a.begin(),a.end(),std::greater<int>())

using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
	string s;
	cin >> s;
	if (s[0] != s[1] || s[1] != s[2])cout << "Yes" << endl;
	else cout << "No" << endl;
}