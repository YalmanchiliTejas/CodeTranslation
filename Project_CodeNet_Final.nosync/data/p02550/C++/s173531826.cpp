#include <bits/stdc++.h>
#define bug1(x) cout<<#x<<" = "<<x<<endl
#define bug2(x,y) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<endl
#define bug3(x,y,z) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<endl
#define bug4(x,y,z,m) cout<<#x<<" = "<<x<<" "<<#y<<" = "<<y<<" "<<#z<<" = "<<z<<" "<<#m<<" = "<<m<<endl

using namespace std;

template<class T> 
ostream& operator<<(ostream &os, vector<T> input) {
    os << "[ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "]";
}

template<class T> 
ostream& operator<<(ostream &os, set<T> input) {
    os << "{ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "}";
}

template<class T> 
ostream& operator<<(ostream &os, unordered_set<T> input) {
    os << "{ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "}";
}

template<class T> 
ostream& operator<<(ostream &os, multiset<T> input) {
    os << "{ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "}";
}

template<class T> 
ostream& operator<<(ostream &os, unordered_multiset<T> input) {
    os << "{ ";
    for(auto elem : input) { 
		os << elem << " ";
	}
	return os << "}";
}

template<class L, class R> 
ostream& operator<<(ostream &os, map<L,R> input) {
    os << "{ ";
    for(auto elem : input) { 
		os << "(" << elem.first << "," << elem.second << ") ";
	}
	return os << "}";
}

template<class L, class R> 
ostream& operator<<(ostream &os, unordered_map<L,R> input) {
    os << "{ ";
    for(auto elem : input) { 
		os << "(" << elem.first << "," << elem.second << ") ";
	}
	return os << "}";
}

#define ll long long
const int MAXN = 1000005;
const ll INF = 1e18;
const int MOD = 1e9 + 7;

class TaskE {
private:

public:
	void solveOne(int it){
		ll n, x, mod;
		cin >> n >> x >> mod;
		vector<ll> sum(MAXN, 0);
		vector<int> where(mod, -1);
		ll ans = 0;
		for(int it = 1; it <= n; it++) {
			sum[it] = x;
			ans += x;
			if(where[x] == -1) {
				where[x] = it;
			} else {
				ll ans2 = 0;
				for(int j = 1; j < where[x]; j++) {
					ans2 += sum[j];
				}
				ll tot = 0;
				for(int j = where[x]; j < it; j++) {
					tot += sum[j];
				}
				ll sz = it - where[x];
				ll ini = where[x] - 1;
				//ini + k * sz <= n
				ll k = (n - ini) / sz;
				ans2 += k * tot;
				ll rem = n - (ini + k * sz);
				for(int j = where[x]; rem > 0 ; j++, rem--) {
					ans2 += sum[j];
				}
				cout << ans2 << endl;
				return;
			}
			x = (x*x)%mod;
		}
		cout << ans << endl;
	}

	void solve(){
		int tc = 1;
		for(int it = 1; it <= tc; it++){
			solveOne(it);
		}
	}
};


int main(){
	ios_base::sync_with_stdio(false);
	TaskE solver;
	solver.solve();
	return 0;
}
