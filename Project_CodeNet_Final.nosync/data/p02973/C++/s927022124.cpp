#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

int main(){
	ll n;cin>>n;
	vector<ll> a(n);
	for(int i = 0; i < n; i++) {
		cin>>a[i];
	}
	multiset<ll> s;
	for(int i = 0; i < n; i++) {
		auto ite = s.lower_bound(a[i]);
		if (ite != s.begin()){
			s.erase(--ite);
		}
		s.insert(a[i]);
	}
	cout << s.size() << endl;
	return 0;
}