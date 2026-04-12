#include <iostream>
#include <fstream>
#include <cmath>  
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string> 
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>

using namespace std;
using ll = long long;

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;

#define REP(i,n) for(int i = 0; i < int(n); i++)
#define FOR(i, m, n) for(int i = int(m);i < int(n);i++)
#define ALL(obj) (obj).begin(),(obj).end()

const ll MOD = (ll)1e9 + 7;
const ll HINF = (ll)1e18;
const ll LINF = (ll)1e9;
const long double PI = 3.1415926535897932384626433;

template<class T> void corner(bool flg, T hoge) {
	if (flg) {
		cout << hoge << endl;
		exit(0);
	}
	else return;
}

template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {
	o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;
}

template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {
	o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}

template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {
	o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;
}

template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {
	o << "{" << obj.first << ", " << obj.second << "}"; return o;
}

template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {
	o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;
}

void print(void) {
	cout << endl;
}

template <class Head> void print(Head&& head) {
	cout << head;
	print();
}

template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {
	cout << head << " ";
	print(forward<Tail>(tail)...);
}

void YN(bool flg) {
	cout << ((flg) ? "YES" : "NO") << endl;
}

void Yn(bool flg) {
	cout << ((flg) ? "Yes" : "No") << endl;
}

void yn(bool flg) {
	cout << ((flg) ? "yes" : "no") << endl;
}

V<ll> dp1(60,0),dp2(60,0);
ll N,X,idx = 0,ans = 0;

void dfs(int deep){

	if (deep == 0){
		if (idx + 1 <= X) {
			idx += 1;
			ans += 1;
		}
		return;
	}

	if (idx == X) return;

	if(idx + 1 <= X){
		idx += 1;
	}

	if (idx == X) return;

	if (idx + dp1[deep-1] <= X) {
		idx += dp1[deep - 1];
		ans += dp2[deep - 1];
	}
	else dfs(deep - 1);

	if (idx == X) return;

	if (idx + 1 <= X) {
		idx += 1;
		ans += 1;
	}

	if (idx == X) return;

	if (idx + dp1[deep - 1] <= X) {
		idx += dp1[deep - 1];
		ans += dp2[deep - 1];
	}
	else dfs(deep - 1);

	if (idx == X) return;

	if (idx + 1 <= X) {
		idx += 1;
	}
}

int main() {
	dp1[0] = dp2[0] = 1;
	FOR(i, 1, 51) dp1[i] = 2LL * dp1[i-1] + 3LL;
	FOR(i, 1, 51) dp2[i] = 2LL * dp2[i-1] + 1LL;
	
	cin >> N >> X;
	dfs(N);
	cout << ans << endl;
	

	return 0;
}

