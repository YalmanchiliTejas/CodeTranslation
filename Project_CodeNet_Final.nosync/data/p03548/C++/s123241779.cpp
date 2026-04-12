#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
#include<fstream>
#include<utility>
#include<bitset>
#include<map>
#include<deque>
#include<cmath>
#include<random>
#include<string.h>
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define rep(N) for (int i = 0; i < N; ++i)
#define Rep(a, b) for (int i = a; i < b; ++i)
#define For(i, N) for (int i = 0; i < N; ++i)
#define all(v) v.begin(), v.end()
#define rev(v) v.rbegin(), v.rend()
#define makei(N) int N; cin >> N;
#define makel(N) ll N; cin >> N;
#define makes(s) string s; cin >> s;
#define maked(d) double d; cin >> d;
#define makev(v, N) vi v(N); rep(N)cin >> v[i];
#define mod 1000000007
#define re return 0
#define cm(i) (Y+Z)*i + Z

using namespace std;
using ll = long long int;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;
using pii = pair<int, int>;
using pis = pair<int, string>;
using msi = map<string, int>;

template<typename T>
void say(T s) {
	cout << s << "\n";
}

template<typename T>
void say(vector<T> s) {
	auto itr = s.begin();
	cout << *(itr++);
	while (itr != s.end()) {
		cout << " " << *(itr++);
	}
	cout << "\n";
}

void yn(bool b) {
	if (b)say("Yes");
	else say("No");
}

int main() {
	int X, Y, Z;
	cin >> X >> Y >> Z;
	int i = 0;
	while (cm(++i) <= X);
	say(i - 1);
}
