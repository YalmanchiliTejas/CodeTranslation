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
#define dump(x) cerr << #x << " = " << (x) << endl;
typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<string> VS;
typedef vector<vector<int>> VVI;
typedef pair<int, int> PII;
const int inf = (int)1e9;
const long long mod = (long long)1e9 + 7;
const double pi = acos(-1.0);

template <class T>void Sort(vector<T> & a) { sort(a.begin(), a.end()); }
template <class T>void ReSort(vector<T>& a) { sort(a.rbegin(), a.rend()); }
template <class T>void Reverse(vector<T>& a) { reverse(a.begin(), a.end()); }
template <class T>void Unique(vector<T>& a) { a.erase(unique(a.begin(), a.end()), a.end()); }
template <class T>T Sum(vector<T> a, T init = 0) { return accumulate(a.begin(), a.end(), init); }

//INPUT//
void CINPUT() {}
template<class H, class ...T> void CINPUT(H&& h, T&& ...t) { cin >> h; CINPUT(forward<T>(t)...); }
#define in(...) int __VA_ARGS__; CINPUT(__VA_ARGS__);
#define In(T,...) T __VA_ARGS__; CINPUT(VA_ARGS__);
#define Vin(T,name,n) int n; cin>>n; vector<T> name(n); rep(i,n)cin>>name[i];
#define VIn(T,name,n) vector<T> name(n); rep(i,n)cin>>name[i];

//OUTPUT//
void print() { cout << endl; }
template <class H> void print(H&& h) { cout << h << endl; }
template <class H, class... T> void print(H&& h, T&& ... t) { cout << h << " "; print(forward<T>(t)...); }
template<class T>void out(T n) { cout << n << endl; }
template<class T>void out(vector<T> a, string sep = " ", string end = "\n") { for (int i = 0; i < (int)a.size(); ++i)cout << a[i] << (i == (int)a.size() - 1 ? end : sep); }
void yes(bool f) { puts(f ? "yes" : "no"); }
void Yes(bool f) { puts(f ? "Yes" : "No"); }
void YES(bool f) { puts(f ? "YES" : "NO"); }
void poss(bool f) { puts(f ? "possible" : "impossible"); }
void Poss(bool f) { puts(f ? "Possible" : "Impossible"); }
void POSS(bool f) { puts(f ? "POSSIBLE" : "IMPOSSIBLE"); }

int main() {
	in(n);
	out(800 * n - n / 15 * 200);
}