#include "bits/stdc++.h"
using namespace std;
#define dbg(var) cout<<#var<<"="<<var<<" "
#define nl cout<<"\n"
#define fr(i,n) for(int i=0;i<n;i++)
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define fast ios::sync_with_stdio(false);cin.tie(0);
#define vi vector<int>
#define vvi vector<vi>
#define pb push_back
#define fa(v) for(auto &i:v)
#define all(v) v.begin(),v.end()
#define sz(v) (int)(v.size())
#define int long long
const int N = 1e5 + 10;
int phi[N];
void phi_1_to_n(int n = N - 5) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
int fpow(int a,int b,int mod){
	int r = 1;
	for(;b;b>>=1,a=a*a%mod){
		if(b & 1) r = r * a%mod;
	}
	return r;
}
int32_t main()
{
    phi_1_to_n();
    int n,x,m; cin >> n >> x >> m;
    vi v{x};set<int>s{x};
    map<int,int> idx; idx [x] = 0;
    fr(_,3*m){
    	int nx = (x * x) % m;
    	if(s.find(nx) != s.end()) break;
    	v.push_back(nx); 
    	idx[nx] = _ + 1;
    	s.insert(nx);
    	x = nx;
    }
    int id =  idx[v.back()*v.back()%m];
    n -= id;
    int cyc = v.size() - id;
    // dbg(cyc);nl;
    int ans = 0;
    fr(i,id) ans += v[i];
    int sm = 0;
   if(cyc)rep(i,id,v.size()-1) ans += (n/cyc) * v[i];
   // cout << (n % cyc);nl;
   for(int i=id,cnt=0;cnt<n%cyc;cnt++,i++){
   	ans += v[i];
   }
   cout << ans;
}