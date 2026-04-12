#include <bits/stdc++.h>
using namespace std;
#define fst first
#define sec second
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;
const ll INF=LLONG_MAX,MOD=1e9+7;
const int L=17,N=1<<L;

ll n;

int main(){
	ios::sync_with_stdio(false);
	string s;cin>>s;n=s.size();
	for(int i=1;i<n;i++){
		if(s[i]=='C'&&s[i-1]=='A')
			return cout<<"Yes",0;
	}
	cout<<"No";
	return 0;
}