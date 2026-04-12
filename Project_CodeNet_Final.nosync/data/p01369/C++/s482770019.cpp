#define _CRT_SECURE_NO_WARNINGS // #pragma warning(disable:4996)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
using namespace std; 

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
#define len(x) ((int)(x).size())
#define tmax(a,b,c) max((a),max((b),(c)))
#define tmin(a,b,c) min((a),min((b),(c)))
#define debug(x) cerr << #x << " is " << x << endl;

typedef pair<int, int> Pii;
typedef vector<int> Vi;
typedef vector<vector<int> > VVi;
typedef long long ll;
const int inf = 2e9;
const ll ll_inf = 1e17;
const int mod = 1e9 + 7;
const long double eps = 1e-10;

int main()
{
	set<char> r;
	r.insert('y');
	r.insert('u');
	r.insert('i');
	r.insert('o');
	r.insert('p');
	r.insert('h');
	r.insert('j');
	r.insert('k');
	r.insert('l');
	r.insert('n');
	r.insert('m');

	while(1) {
		string s;
		cin >> s;
		if (s.size() == 1 && s[0] == '#') break;
		bool f;
		auto it = r.find(s[0]);
		if (it == r.end()) f = false;
		else f = true;
		int cnt = 0;

		rep(i,0,s.size()) {
			auto it = r.find(s[i]);
			if (f) {
				if (it == r.end()) {
					f = false;
					cnt++;
				}
			}
			else {
				if (it != r.end()) {
					f = true;
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}

	return 0;
}