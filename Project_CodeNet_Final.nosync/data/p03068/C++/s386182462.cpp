#include <iostream>
#include <vector>
#include <numeric>
#include <tuple>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <limits>
#include <unordered_map>
#include <type_traits>
#include <map>
#include <cstdio>
#include <string>

using namespace std;
using str = string;

#define rep(a,l,r) for(int a=(l);a<(r);a++)
#define get cin>>
#define put cout<<

int gcd_euclid(int u, int v) {
  int r;
  while (0 != v) {
    r = u % v; u = v; v = r; /* swap */
  }
  return u;
}

// 最大公約数算出
int calc_gcd(const vector<int> vec){
	int gcd = *min_element(vec.begin(), vec.end());
	for (const int ele: vec){
		gcd = gcd_euclid(gcd,ele);
	}
	return gcd;
}

// 最小公倍数
int calc_lcm(const vector<int> vec) {
	int tmp = 1;
	for (const int ele: vec){
		tmp *= ele;
	}
	int gcd = calc_gcd(vec);
	return tmp/gcd;
}

std::string join(const std::vector<std::string>& v, const char* delim = 0) {
  std::string s;
  if (!v.empty()) {
    s += v[0];
    for (decltype(v.size()) i = 1, c = v.size(); i < c; ++i) {
      if (delim) s += delim;
      s += v[i];
    }
  }
  return s;
}

// nが奇数、偶数の場合の場合分け
// n & 1 ? odd : even

// distinctはsortしてunique + erase
// https://qiita.com/ysk24ok/items/30ae72f4f1060b088588
//sort(vec.begin(), vec.end());
//vec.erase(unique(vec.begin(), vec.end()), vec.end());

void run() {
	int n,k;
	string s;

	get n; get s; get k;

	char m = s[k - 1];

	for(char& i : s) {
		if (i != m) {
			i = '*';
		}
	}

	put s;

}


int main() {ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);run();return 0;}
