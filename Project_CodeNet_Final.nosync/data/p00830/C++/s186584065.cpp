#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <set>
#include <map>
#include <string.h>
#include <iomanip>

#define rep(i, j) for(int i = 0; i < j; i++)
#define all(i) i.begin(), i.end()
#define clr(n) memset(n,0,sizeof(n))
#define ll long long

using namespace std;
#define double long double

vector<string> split(string s) {
	vector<string> r;
	string n;
	s += '/';
	rep(i, s.size()) {
		if (s[i] == '/') {
			r.push_back(n);
			n.clear();
		}
		else {
			n.push_back(s[i]);
		}
	}
	if (r.back().size() == 0) {
		r[r.size() - 1] = "index.html";
	}
	return r;
}

#include <functional>

int main()
{
	int n, m;
	while (cin >> n >> m && n) {
		vector<map<string, int>> mp;
		vector<map<string, int>> fs;
		vector<int> p;
		int count = 0;

		function<void(int,vector<string>)> make = [&](int now, vector<string> vs) {
			string s = vs[0];
			if (vs.size() == 1) {
				fs[now][s] = count++;
				return;
			}
			if (mp[now].count(s) == false) {
				mp[now][s] = mp.size();
				mp.push_back(map<string, int>());
				fs.push_back(map<string,int>());
				p.push_back(now);
			}
			vs.erase(vs.begin());
			make(mp[now][s], vs);
		};

		function<int(int, vector<string>, int)> search = [&](int now, vector<string> vs, int f) {
			if (vs.size() == 0)return -1;
			if (vs[0] == "..") {
				vs.erase(vs.begin());
				if (p[now] == 0)return -1;
				return search(p[now], vs, f);
			}
			if (vs[0] == ".") {
				vs.erase(vs.begin());
				return search(now, vs, f);
			}
			string s = vs[0];
			if (vs.size() == 1) {
				if (fs[now].count(s)) {
					return fs[now][s];
				}else{
					return -1;
				}
			}
			if (mp[now].count(s) == false) {
				return -1;
			}
			vs.erase(vs.begin());
			return search(mp[now][s], vs, f);
		};

		mp.push_back(map<string, int>());
		fs.push_back(map<string,int>());
		p.push_back(-1);

		rep(i, n) {
			string s;
			cin >> s;
			auto vs = split(s);
			make(0, vs);
		}
		rep(i, m) {
			string a, b;
			cin >> a >> b;
			int ta = search(0, split(a), 0);
			int tb = search(0, split(b), 0);
			if (ta == -1) {
				a += "/index.html";
				ta = search(0, split(a), 0);
			}
			if (tb == -1) {
				b += "/index.html";
				tb = search(0, split(b), 0);
			}
			if (ta == -1 || tb == -1) {
				cout << "not found" << endl;
				continue;
			}
			if (ta == tb) {
				cout << "yes" << endl;
				continue;
			}
			cout << "no" << endl;
		}

	}

	return 0;
}