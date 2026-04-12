#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <istream>
#include <ostream>

#include <cstdlib>
#include <cmath>
#include <cstdio>

using namespace std;

#define fi first
#define se second
#define mkp make_pair
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define rep(i,n) for(ll i=0; i < (n); ++i)
#define rrep(i,n) for(ll i=((n)-1); i >= 0; --i)

#define OPLT(T) bool operator<(const T & lop_, const T & rop_)
#define OPEQ(T) bool operator==(const T & lop_, const T & rop_)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

istream& operator>>(istream& istr, __float128& obj) { double d; istr >> d; obj = d; return istr; };
ostream& operator<<(ostream& ostr, __float128& obj) { ostr << static_cast<double>(obj); return ostr; };

int edge[10][10];

int main() {
	int N, M;
	cin >> N >> M;
	rep(i,M) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		edge[a][b] = edge[b][a] = 1;
	}
	vector<int> v(N);
	rep(i,N) v[i] = i;
	int res = 0;
	do {
		bool f = v[0] == 0;
		for(int i = 1; i < N; i++)
			if(!edge[v[i]][v[i-1]]) f = false;
		res += f;
	} while(next_permutation(all(v)));
	cout << res << endl;
	return 0;
}
