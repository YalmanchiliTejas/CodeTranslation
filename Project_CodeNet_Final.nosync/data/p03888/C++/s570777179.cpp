#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define FOR(i, m, n) for(int i=(m); i<(n); ++i)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define Cout(x) cout << (x) << endl
#define Cout2(x, y) cout << (x) << " " << (y) << endl
#define dump(x) cerr << #x << " = " << (x) << endl;
typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
const int inf = (int)1e9;
const double pi = acos(-1.0);
template <class A>ostream & operator<<(ostream & o, const vector<A> & p) { o << "{"; for (int i = 0; i < (int)p.size(); ++i)o << (i > 0 ? ", " : "") << p[i]; o << "}"; return o; }
template <class A, class B>ostream & operator<<(ostream & o, const pair<A, B> & p) { o << "{" << p.first << ", " << p.second << "}"; return o; }
template <class A, class B>ostream& operator<<(ostream & o, const map<A, B> & p) { o << "{"; for (auto it = p.begin(); it != p.end(); ++it) o << (it != p.begin() ? ", " : "") << *it; o << "}"; return o; }
template <class A>ostream & operator<<(ostream & o, const set<A> & p) { o << "{"; for (auto it = p.begin(); it != p.end(); ++it) o << (it != p.begin() ? ", " : "") << *it; o << "}"; return o; }
void print() { cerr << endl; }
template <class H> void print(H && h) { cerr << h << endl; }
template <class H, class... T> void print(H && h, T && ... t) { cerr << h << " "; print(forward<T>(t)...); }

int main() {
	double r1, r2; cin >> r1 >> r2;
	printf("%.20f\n", 1 / (1 / r1 + 1 / r2));
}