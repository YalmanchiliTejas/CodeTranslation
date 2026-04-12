#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define ERASE(v,i) (v).erase(remove(all(v),i),(v).end())
#define rep(i,n) for(int i=0;i<(int)n;++i)
#define each(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
#define LINE cerr<<"LINE: "<<__LINE__<<endl;

inline int toInt(string s){int v;istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x){ostringstream sout;sout<<x;return sout.str();}
template<class T> void preview(T a,T b){for(T it=a;it!=b;++it)cerr<<*it<<" ";cerr<<endl;}

const int INF = 100000000;
const double PI = acos(-1.0), EPS = 1e-10;

int main() {
	string right_s = "yuiophjklnm";
	string left_s = "qwertasdfgzxcvb";
	set<char> right;
	set<char> left;

	for(int i = 0; i < right_s.length(); i++) right.insert(right_s[i]);
	for(int i = 0; i < left_s.length(); i++) left.insert(left_s[i]);

	for(string s; getline(cin, s), s != "#";) {
		int ans = 0;
		bool prev = (right.find(s[0]) != right.end());
		for(int i = 1; i < s.length(); i++) {
			if(prev != (right.find(s[i]) != right.end())) {
				ans++;
				prev = (right.find(s[i]) != right.end());
			}
		}
		cout << ans << endl;
	}
	return 0;
}