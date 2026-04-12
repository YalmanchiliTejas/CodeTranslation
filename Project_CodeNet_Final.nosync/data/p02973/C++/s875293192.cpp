#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(x,arr) for(auto& x:arr)
#define VI vector<int>
#define PII pair<int, int>
#define FI first 
#define SE second
#define ALL(x) (x).begin(), (x).end()
const int INF=1<<30; const ll LINF=1LL<<60 ; const ll mod=1e9+7 ;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
//-------------------
ll a[100000+5];

int main() {
	int n;
	scanf("%d", &n);
	multiset<int> M;
	FOR(i,1,n) {
		ll x;
		scanf("%lld", &x);
		auto it=M.lower_bound(x);
		if(it==M.begin()) M.insert(x);
		else {
			it--;
			M.erase(it);
			M.insert(x);
		}
	}
	cout<<M.size()<<endl;
	
}