#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define all(V) (V).begin(), (V).end() 
#define x first
#define y second

using namespace std;
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}


using namespace std;

typedef long long ll;
template <typename T> using V = vector <T>;

const ll mod = 1e9 + 7;
const int MM = 1e4 + 5, KM = 105;

inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}

inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

V <V <ll>> dp(MM, V <ll> (KM, 0));
int K;
void pre() {
	dp[0][0] = 1;
	for(int dig = 1; dig < MM; dig++) {
		for(int cd = 0; cd <= 9; cd++) {
			for(int rem = 0; rem < K; rem++) {
				dp[dig][rem] = add(dp[dig][rem], dp[dig - 1][(rem - cd + 10 * K) % K]);
			}
		}
	}
}
ll ansFor(V <int> &N, int ind, ll rem) {
	if(ind == -1) {
		return rem == 0;
	}
	ll cnt0 = 0;
	for(int d = 0; d < N[ind]; d++) {
		cnt0 = add(cnt0, dp[ind][(-rem - d + 10 * K) % K]);
	}
	ll cnt1 = ansFor(N, ind - 1, (rem + N[ind]) % K);
	return add(cnt0, cnt1);
}

int main() {fio;
	string N;
	cin >> N >> K;
	pre();
	V <int> num(N.size());
	for(int i = 0; i < N.size(); i++) {
		num[N.size() - i - 1] = N[i] - '0';
	}
	cout << sub(ansFor(num, N.size() - 1, 0), 1) % mod;
    return 0;
}