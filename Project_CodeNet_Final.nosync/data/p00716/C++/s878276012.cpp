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
	int M; cin >> M;
	rep(m, M) {
		int start;
		int year;
		int N;
		cin >> start >> year >> N;
		vector<int> sum(N);

		rep(i,N) {
			bool hukuri;
			double par;
			int cost;
			cin >> hukuri >> par >> cost;

			if(!hukuri) {
				int now = start;
				int benefit = 0;
				rep(j,year) {
					benefit += now * par;
					now -= cost;
				}

				sum[i] = now + benefit;
			} else {
				int now = start;
				rep(j,year) {
					now *= 1.0 + par;
					now -= cost;
				}
				sum[i] = now;
			}
		}
		cout << *max_element(all(sum)) << endl;
	}

	return 0;
}