#include<bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for(int (i) = 0; (i) < (n); (i)++)
#define rrep(i, n) for (int (i) = 1; (i) <= (n); (i++))
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define yn {puts("Yes");}else {puts("No");}
#define printd(x) printf("%.12f\n", x);
template<class T> bool chmin(T& a, const T& b) {if (a > b) {a = b; return 1;} return 0;}
template<class T> bool chmax(T& a, const T& b) {if (a < b) {a = b; return 1;} return 0;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

bool is_prime(long long _Num){
    if(_Num < 2)return false;
    if(_Num % 2 == 0){
        if(_Num == 2)return true;
        else return false;
    }
    bool prime = true;
    for(long long i = 3; i <= sqrt(_Num); i += 2){
        if(_Num % i == 0){
            prime = false;
            break;
        }
    }
    return prime;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep (i, n) cin >> a[i];

	multiset<int> st;
	rep (i, n) {
		if (!i) {
			st.insert(a[i]);
			continue;
		}
		auto lb = st.lower_bound(a[i]);
		lb--;
		if (a[i] <= *st.begin()) st.insert(a[i]);
		else {
			st.erase(lb);
			st.insert(a[i]);
		}
	}

	cout << st.size() << endl;
	return 0;
}