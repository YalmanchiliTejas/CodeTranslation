#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define nav(...) "[ " << #__VA_ARGS__ ": " << (__VA_ARGS__) << " ] "
#define oo INT_MAX/2
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
template<class T> struct rge { T b, e; };
template<class T> rge<T> range(T i, T j) { return rge<T>{i, j}; }
struct debug {
#ifdef LOCAL
	~debug() {cerr<<endl;}
	template<class T> debug& operator<<(T x) {cerr<<boolalpha<<x; return *this;}
	template<class B, class C> debug& operator<< (pair<B, C> x){return *this<<"("<<x.first<<", "<<x.second<<")";}
	template<class T> debug& operator<<(rge<T> x) {
		*this<<"[";for(auto it=x.b;it!=x.e;it++){*this<<", "+2*(it==x.b)<<*it;}return *this<<"]";}
	template<class T> debug& operator<<(vector<T> x){ return *this<<range(all(x));}
#else
	template<class T> debug& operator <<(const T&) {return *this;}
#endif
};

string s;

int rec(string& cur, int i, int k) {
	int n = cur.length();
	if(i == n) {
		if(k == 0) {
			return cur <= s;
		} else {
			return 0;
		}
	} else if(k == 0){
		return cur <= s;
	} else {
		int ans = rec(cur, i+1, k);
		for(char c = '1'; c <= '9'; c++) {
			cur[i] = c;
			ans += rec(cur, i+1, k-1);
			cur[i] = '0';
		}
		return ans;
	}
}

bool solve(void) {

	int k;
	cin>>s>>k;
	int n = s.length();
	//cout << n << endl;
	string cur(n, '0');

	cout << rec(cur, 0, k)<< endl;
	
	return true;
}

int main(int argc, char* argv[]) {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
	return 0;
}
