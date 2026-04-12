#include <iostream>
#include <float.h>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <fstream>
#include <queue>
#include <math.h>
#include <set>
#include <stdlib.h>
#include <time.h>
#include <list>
#include <stack>
#include <queue>

#define For(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)  For(i,0,n)

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))
#define SORT(c) sort((c).begin(),(c).end())
#define vi(m,a) vector<int> m(a)
#define vti(m,a,i) vector<vector<int>> m(a,vector<int>(i))
#define ALL(it,a) for(auto it = a.begin(); it!=a.end(); it++)
#define Fe(it,a) for(auto &it : a)
#define all(a) begin(a),end(a)

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
#define WARU 1000000007;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

string result;
string str;
int n;
bool solve(vector<char> d,string init) {
	For(i, 1, n) {
		if (d[i] == 'S') {
			if (str[i] == 'o') {
				if (d[i - 1] == 'S')
					d[(i + 1) % n] = 'S';
				else
					d[(i + 1) % n] = 'W';
			}
			else {
				if (d[i - 1] == 'S')
					d[(i + 1) % n] = 'W';
				else
					d[(i + 1) % n] = 'S';
			}

		}
		else {
			if (str[i] == 'o') {
				if (d[i - 1] == 'S')
					d[(i + 1) % n] = 'W';
				else
					d[(i + 1) % n] = 'S';
			}
			else {
				if (d[i - 1] == 'W')
					d[(i + 1) % n] = 'W';
				else
					d[(i + 1) % n] = 'S';
			}
		}
	}
	if (str[0] == 'o') {
		if (d[0] == 'S' && d[n - 1] != d[1]) {
			return false;
		}
		if (d[0] == 'W' && d[n - 1] == d[1]) {
			return false;
		}
	}
	else {
		if (d[0] == 'S' && d[n - 1] == d[1]) {
			return false;
		}
		if (d[0] == 'W' && d[n - 1] != d[1]) {
			return false;
		}
	}
	string str(d.begin(),d.end());
	if (d[n - 1] == init[0] && d[0] == init[1] && d[1] == init[2]) {
		string str(d.begin(),d.end());
		result = str;
		return true;
	}
	return false;
}


int main() {
	cin >> n;
	cin >> str;
	vector<char> d(n);
	auto flag = false;
	auto tmp = d;
	string uso[] = { "SSW","WSS","SWS","WWW" };
	string honto[] = { "SSS","WSW","SWW","WWS" };
	if (str[0] != 'o') {
		rep(i, 4) {
			tmp[0] = uso[i][1];
			tmp[1] = uso[i][2];
			tmp[n - 1] = uso[i][0];
			flag = solve(tmp,uso[i]);
			if (flag)
				break;
		}
	}
	else {
		rep(i, 4) {
			tmp[0] = honto[i][1];
			tmp[1] = honto[i][2];
			tmp[n - 1] = honto[i][0];
			flag = solve(tmp,honto[i]);
			if (flag)
				break;
		}
	}
	if (flag)
		cout << result << endl;
	else
		cout << -1 << endl;
}

