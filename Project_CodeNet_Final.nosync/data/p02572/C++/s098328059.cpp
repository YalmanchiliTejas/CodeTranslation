//---------------------------------------------------------MANAS UNIYAL---------------------------------------------------------
//                                                        NEVER  GIVE  UP
#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define ll long long
#define pb push_back
#define fi first 
#define se second
#define pii pair<ll,ll>
#define INF 0x3f3f3f3f
#define LINF 98765432123456789
#define testcases() ll t; cin>>t; while(t--)
#define debug cout<<"Hello\n";
#define debug1(x) cout<<#x<<" "<<x<<"\n";
#define debug2(x,y) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<"\n";
#define debug3(x,y,z) cout<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<"\n";
#define debug4(w,x,y,z) cout<<#w<<" "<<w<<" "<<#x<<" "<<x<<" "<<#y<<" "<<y<<" "<<#z<<" "<<z<<"\n";
#define rep(i,start,end) for(ll i=start;i<end;i++)
#define sz(x) (ll)((x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
//------------------------------------------------------------------------------------------------------------------------------
#define mod 1000000007
int main()
{
	
	#ifndef ONLINE_JUDGE
	freopen("C:/Users/DELL/Desktop/input.txt", "r", stdin);
	#endif

	fast;
	ll n,ans = 0;
	cin>>n;
	vector<ll> v(n);
	for(ll i=0;i<n;i++) {
		cin>>v[i];
	}
	vector<ll> prefix(n,0);
	prefix[0] = v[0];
	for(int i=1;i<n;i++) {
		prefix[i] = (prefix[i-1] + v[i]) % mod;
	}
	for(ll i=n-1;i>0;i--) {
		ans = (ans + (v[i] * prefix[i-1]) % mod) % mod;
	}
	cout<<ans;
	return 0;
}
