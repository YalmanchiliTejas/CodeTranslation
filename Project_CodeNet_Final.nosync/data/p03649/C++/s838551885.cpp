#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dd;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

#define FOR(i,a,b) for (int (i) = (a); (i) < (b); (i)++)
#define DOW(i,b,a) for (int i = (b); i >= (a); i--)
#define pb(a) push_back(a)
#define ALL(a) (a).begin(),(a).end()
#define fi first
#define se second

template<typename T>
void print_array(T* arr, int num) {
   FOR(i, 0, num) cout << arr[i] << ' ';
   cout << endl;
}

template<typename T> 
void print_vector(vector<T> vec) {
   FOR(i,0,vec.size()) cout << vec[i] << ' ';
   cout << endl;
}

int n;
ll arr[60];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
   // freopen("test.txt", "r", stdin);
	cin >> n;
	FOR(i,0,n) cin >> arr[i];
	ll ans = 0;
	while (1) {
		int chk = 1;
		FOR(i,0,n) {
			ll cur = arr[i] / n;
			ans += cur;
			if (cur > 0) chk = 0;
			arr[i] = arr[i] % n;
			FOR(j,0,n) if (j != i) arr[j] += cur;
		}
		if (chk) break;
	}
	cout << ans;
}