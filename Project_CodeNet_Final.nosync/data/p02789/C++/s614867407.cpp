#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define vcout(v) rep(i,v.size()) cout << v[i] << " "; cout << endl
#define mcout(m) rep(j,m.size()){vcout(m[j]);}
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
const ll MOD = 1e9 + 7;

void mainsolve(){

	ll n,m;
	cin >> n >> m;
	string res;

	if(n==m) res = "Yes";
	else res = "No";
	cout << res << endl;
	return;
}

int main(){
	
	//ll TC;cin>>TC;rep(I,TC){cout<<"case:"<<I+1<<"---"<<endl; // comment out!
		mainsolve();
	//} // comment out!
	return 0;
}