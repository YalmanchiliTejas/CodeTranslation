#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define Test ll t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define rep(i, a, b) for(ll i=a;i<b;i++)
#define repR(i,a,b) for(ll i=a;i>=b;i--)
#define loopS(i,a,b,step) for(ll i=a;i<b;i+=step)
#define loopRS(i,a,b,step) for(ll i=a;i>=b;i-=step)
#define ull unsigned long long int
#define pll pair<ll,ll>
#define puu pair<ull, ull>
#define V vector
#define M map
#define UM unordered_map
#define mp(x,y) make_pair(x,y)
#define pb push_back
#define pf push_front
#define ff first
#define ss second
#define inf INT_MAX
#define S3(a,b,c) cin >> a >> b >> c
#define S2(a,b) cin >> a >> b
#define debug(x) cerr << #x << " = " << x << endl;
#define debug2(x,y) cerr << #x << " = " << x << " " << #y << " = " << y << endl;
#define debug3(x,y,z) cerr << #x << " = " << x << " " << #y << " = " << y <<  " " << #z << " = " << z << endl;
using namespace std;

void input(ll n, ll arr[]) {
	rep(i, 0, n)cin >> arr[i];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cout.tie(NULL);
	ll x; cin >> x;
	if (x >= 30)cout << "Yes\n";
	else cout << "No\n";
}
