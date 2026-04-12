#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P,ll> Pll;
typedef pair<P,P> PP;
#define rep(i,a,n) for(int i = a;i < n;i++)
#define LINF (ll)1e17
#define INF 1e9
#define MOD 1e9+7
#define sMOD 1e5
#define fs first
#define sc second

ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}


signed main(){
	ll n,k;
	string s;
	
	cin >> n >> s >> k;
	
	char memo = s[k-1];
	
	rep(i,0,s.size()){
		if(memo != s[i]) s[i] = '*';
	}
	
	cout << s << endl;
	return 0;

}