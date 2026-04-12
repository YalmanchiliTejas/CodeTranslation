#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL

using ll = long long;
template<typename T>
using vec = vector<T>;
using P = pair<ll, ll>;

template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val)
{
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e18;
const ll mod = 1e9 + 7;


int main(){
	IOS;
	int n;
	ll sum0 = 0, sum1 = 0;
	cin >> n;
	vec<ll> a(n),t(n),s(n);
	REP(i,n)cin >> a[i];
	sort(ALL(a));
	REP(i,n){
		if(i == 0){
			s[i] = -1;
			t[i] = 1;
		}
		else if(i == n - 1){
			if(i % 2 == 0){
				s[i] = -1;
				t[i] = 1;
			}
			else{
				s[i] = 1;
				t[i] = -1;
			}
		}
		else if(i % 2 == 0){
			s[i] = -2;
			t[i] = 2;
		}
		else {
			s[i] = 2;
			t[i] = -2;
		}
	}
	sort(ALL(s));
	sort(ALL(t));
	REP(i,n){
		sum0 += a[i] * s[i];
		sum1 += a[i] * t[i];
	}
	dump(max(sum0,sum1));
}