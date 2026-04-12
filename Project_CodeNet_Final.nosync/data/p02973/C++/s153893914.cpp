/*input
6
3 3 3 2 2 2
*/
#include <bits/stdc++.h>
using namespace std;
#define TEMPLATE

#ifdef TEMPLATE
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<ld, ld> pd;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<vl> vll;
typedef vector<pi> vpi;
typedef vector<vpi> vpii;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
typedef vector<pd> vpd;
typedef vector<bool> vb;
typedef vector<vb> vbb;
typedef std::string str;
typedef std::vector<str> vs;

#define x first
#define y second
#define debug(...) cout<<"["<<#__VA_ARGS__<<": "<<__VA_ARGS__<<"]\n"

const int MOD = 1000000007;
const ll INF = std::numeric_limits<ll>::max();
const int MX = 100101;
const ld PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899862803482534211706798214808651328230664709384460955058223172535940812848111745028410270L;

template<typename T>
pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) { return pair<T, T>(a.x + b.x, a.y + b.y); }
template<typename T>
pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) { return pair<T, T>(a.x - b.x, a.y - b.y); }
template<typename T>
T operator*(const pair<T, T> &a, const pair<T, T> &b) { return (a.x * b.x + a.y * b.y); }
template<typename T>
T operator^(const pair<T, T> &a, const pair<T, T> &b) { return (a.x * b.y - a.y * b.x); }

template<typename T>
void print(vector<T> vec, string name = "") {
	cout << name;
	for (auto u : vec)
		cout << u << ' ';
	cout << '\n';
}

#endif

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	vi sk(N);
	for (int i = 0; i < N; ++i)
		cin >> sk[i];
	set<int> setas;
	map<int, int> kiek;

	for (int i = 0; i < N; ++i)
	{
		auto it = setas.upper_bound(sk[i]);
		if (it == setas.begin()) {
			setas.insert(sk[i]);
			kiek[sk[i]]++;
		}
		else if (it == setas.end()) {
			if (setas.empty()) {
				setas.insert(sk[i]);
				kiek[sk[i]]++;
			}
			else if (*(--setas.end()) == sk[i]) {
				if (setas.size() == 1) {
					kiek[sk[i]]++;
				} else {
					auto itas = --setas.end();
					itas--;
					kiek[*itas]--;
					if (!kiek[*itas])
						setas.erase(itas);

					setas.insert(sk[i]);
					kiek[sk[i]]++;
				}
			}
			else {
				kiek[*(--setas.end())]--;

				if (!kiek[*(--setas.end())])
					setas.erase(--setas.end());

				setas.insert(sk[i]);
				kiek[sk[i]]++;
			}
		}
		else {
			it--;
			if(*it == sk[i]){
				if(it == setas.begin()){
					kiek[sk[i]]++;
					continue;
				} else {
					it--;
				}
			}
			kiek[*it]--;
			if (!kiek[*it])
				setas.erase(it);

			setas.insert(sk[i]);
			kiek[sk[i]]++;
		}
	}
	int ats = 0;
	for (auto u : kiek) {
		ats += u.y;
	}
	printf("%d\n", ats);
}

/* Look for:
* special cases (n=1?)
* overflow (ll vs int?)
* the exact constraints (multiple sets are too slow for n=10^6 :( )
* array bounds
*/

