#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define forn(i,n) for(ll i=0;i<n;i++)
#define nforn(i,n) for(ll i=n-1;i>=0;i--)
#define forne(i,n) for(ll i=1;i<=n;i++)
#define forse(i,s,e) for(ll i=s;i<e;i++)
#define all(v) v.begin(),v.end()
#define MOD 1000000007
#define d1(x) cerr <<"> "<<#x<<" = "<<x<<'\n'
#define d2(x, y) cerr <<"> "<<#x<<" = "<<x<<' '<<#y<<" = "<<y<<'\n'
#define d3(x, y, z) cerr <<"> "<<#x<<" = "<<x<<' '<<#y<<" = "<<y<<' '<<#z<<" = "<<z<<'\n'
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	// cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		if(m>=n)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}