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
	int n,k;cin >> n >> k;
	if(k==0){
		cout << (ll)n*n << endl;
		return 0;
	}
	ll ans=0;
	for(int b=k+1;b<=n;++b){
		int i=k,j=b-1;
		while(i<=n || j<=n){
			if(j>n) ans+=n-i+1;
			else ans+=j-i+1;
			i+=b;
			j+=b;
		}
	}
	cout << ans << endl;
}