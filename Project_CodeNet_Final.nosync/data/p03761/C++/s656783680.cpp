


#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <deque>
#include <complex>
#include <stack>
#include <queue>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <ctime>
#include <iterator>
#include <bitset>
#include <numeric>
#include <list>
#include <iomanip>
using namespace std;


typedef long long LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

typedef vector<int> vint;
typedef vector<vector<int> > vvint;
typedef vector<long long> vll, vLL;
typedef vector<vector<long long> > vvll, vvLL;

#define VV(T) vector<vector< T > >

template <class T>
void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()) {
	v.assign(a, vector<T>(b, t));
}

template <class F, class T>
void convert(const F &f, T &t) {
	stringstream ss;
	ss << f;
	ss >> t;
}


#define REP(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(v) (v).rbegin(),(v).rend()
#define PB push_back


#define MOD 1000000009LL
#define EPS 1e-8


int main() {

	int n;
	cin >> n;
	vector<string> s(n);
	for (int i = 0; i<n; i++) {
		cin >> s[i];
		// cout<<i<<" "<<s[i]<<endl;
	}

	//for (int i = 0; i<n; i++) {
	//	cout << s[i] << endl;
	//}
	std::sort(s.begin(), s.end(), [](string i, string j) {return i.size()<j.size(); });

	//cout << endl;
	/*for (int i = 0; i<n; i++) {
		cout << s[i] << endl;
	}*/
	string common;

	//bool used[50][50] = { false };

	for (int i = 0; i<s[0].size(); i++) {
		char a = s[0].at(i);
		for (int j = 1; j<s.size(); j++) {
			int pos;
			if ((pos = s[j].find(a)) != string::npos) {
				/*if (used[j][pos]) { goto GONEXT; }
				used[j][pos]=true;*/
				s[j][pos] = '0';
			}
			else {

				for (int k = 1; k < s.size(); k++) { if ((pos = s[k].find(a)) != string::npos) { s[k][pos] = a;} }

				goto GONEXT;
			}
		}

		common += a;
	GONEXT:;
	}

	sort(common.begin(), common.end());
	cout << common << endl;

}
