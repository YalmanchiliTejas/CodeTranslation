#include <iostream>
#include <cstdlib>
#include <bitset>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

#define ll long long int
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecchar vector<char>
#define vecstr vector<string>
#define vecbool vector<bool>
#define vec2bool vector<vector<bool>>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s > 0;s--)

#define Pi 3.1415926535897932384626

int main() {
	ll n, ans = 0,count = 0;
	string s="No";
	bool flag = false;

	cin >> n;

	if (n >= 30)
		flag = true;

	if (flag)
		cout << "Yes";
	else
		cout << "No";
}
