#include <bits/stdc++.h>
using namespace std;
#define ff(i,s,n) for(int i=s;i<n;i++)
#define fr(i,s,n) for(int i=n-1;i>=s;i--)
#define llu long long int
const int mod=1000000007;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	vector<int> v(n);
	
	ff(i,0,n)	cin>>v[i];
	
	llu ans=0;
	llu x=0;
	
	ff(i,0,n){
		ans=(ans+(v[i]*x)%mod)%mod;
		x=(x+v[i])%mod;
	}
	cout<<ans;
}

//1
//7 2
//3 5 4 5 1 1 1
