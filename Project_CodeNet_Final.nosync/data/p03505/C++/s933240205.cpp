#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=0;i<(n);++i)

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll k,a,b;cin >> k >> a >> b;
	if(k<=a) cout << 1 << endl;
	else if(a<=b) cout << -1 << endl;
	else{
		ll ans=1;
		k-=a;
		ans+=(k+(a-b)-1)/(a-b)*2;
		cout << ans << endl;
	}
}