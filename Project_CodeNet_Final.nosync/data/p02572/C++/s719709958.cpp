#include <bits/stdc++.h>
using namespace std;
#define all(c) c.begin(),c.end()
#define init(c) memset(c,0,sizeof c)
#define S second
#define F first
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
const int N=20000005;
const int MOD = 1e9+7;
int n,k,x,t,a,b,m;
string s;
vi v;
 
void solve(){
	ll sum = 0;
	cin >> n;
	for(int i =1;i<=n;i++){
		cin >> x;
		sum += x;
		v.push_back(x);
	}
	int ans = 0;
	for(int i =0;i<n;i++){
		sum-=v[i];
		ans = (ans+((sum%MOD)*v[i])%MOD)%MOD;  
	}
	cout << ans;
 
}
 
int main(){

	t=1;
	while(t--){
		solve();
	}
	
	return 0;
}