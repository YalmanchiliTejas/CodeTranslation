#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define fi first
#define se second
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}
#define bit(x) (1ll<<(x))

void mainsolve(){

	ll x;
	cin >> x;
	set<ll> valid = {3, 5, 7};
	if(valid.find(x) != valid.end()) cout << "YES" << endl;
	else cout << "NO" << endl;

	return;
}

int main(){
	
	//ll TC;cin>>TC;rep(I,TC){cout<<"case:"<<I+1<<"---"<<endl; // comment out!
		mainsolve();
	//} // comment out!
	return 0;
}