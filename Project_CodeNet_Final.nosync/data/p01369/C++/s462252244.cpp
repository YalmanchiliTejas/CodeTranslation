#include <iostream>
#include <memory>
#include <memory.h>
#include <cmath>
#include <fstream>
#include <cmath>
#include <numeric>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <cstdio>
#include <map>
#include <iomanip>
#include <list>
#include <cctype>
#include <algorithm>
#include <complex>
#define USE_MATH_DEFINES
using namespace std;

typedef complex<double> xy_t;
typedef pair<xy_t, xy_t> line;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
typedef pair<int, PP> PPP;
const int INF = 1 << 29;
const double EPS = 1E-10;

typedef pair<xy_t, bool> dat;

namespace std{
	bool operator < (const xy_t &a, const xy_t &b){
		return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
	}
}

double cross(const xy_t &a, const xy_t &b){
	return imag(conj(a) * b);
}

double dot(const xy_t &a, const xy_t &b){
	return real(conj(a)*b);
}

int ccw(xy_t a, xy_t b, xy_t c){
	b -= a; c -= a;
	if(cross(b, c) > 0) return 1;
	if(cross(b, c) < 0) return -1;
	if(dot(b, c) < 0) return +2;
	if(norm(b) < norm(c) ) return -2;
	return 0;
}

bool intersectSS(const line &s, const line &t){
	return ccw(s.first, s.second, t.first) * ccw(s.first, s.second, t.second) <= 0 &&
		ccw(t.first, t.second, s.first) * ccw(t.first, t.second, s.second) <= 0;
}

xy_t crosspoint(const line &l, const line &m){
	double a = cross(l.second - l.first, m.second - m.first);
	double b = cross(l.second - l.first, l.second - m.first);
	if(abs(a) < EPS && abs(b) < EPS) return m.first;
	if(abs(a) < EPS) assert(false);
	return m.first + b / a * (m.second - m.first);
}

int nums[] = {
	1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1,
};

int main(){
	string s;
	while(cin >> s && s != "#"){
		int n = s.size();
		int res = 0;
		for(int i = 0; i < n - 1; i++){
			if(nums[s[i]-'a'] != nums[s[i+1] - 'a']) res++;
		}
		cout << res << endl;
	}
	return 0;
}