#include<bits/stdc++.h>
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
#define distance(x1,y1,x2,y2) sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));

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

void YN(bool b) {
	if (b)say("YES");
	else say("NO");
}

template<typename T>
void maxi(T &a, T b) {
	a = max(a, b);
}

template<typename T>
void mini(T &a, T b) {
	a = min(a, b);
}

void exact_say(double x) {
	cout << setprecision(numeric_limits<double>::max_digits10) << x << endl;
}

int main() {
	makei(x);
	YN(x == 7 || x == 5 || x == 3);
}