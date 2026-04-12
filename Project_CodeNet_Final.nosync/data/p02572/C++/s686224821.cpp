#include<bits/stdc++.h>
using namespace std;
 
#define 	pi 				3.14159265358979
#define 	mod 			1000000007
#define 	ll  			long long int
#define 	rep(i, a, b) 	for(ll i = a ; i < b ; i++)
#define     repn(i, a, b)   for(ll i = a ; i > b ; i--)
#define 	mod1 			1000003
#define     mod2            998244353
#define     inf             2e18
#define 	hi   			"hello"
#define 	nl 				"\n"
#define 	ws 				" "
#define 	ff 				first
#define 	ss				second
#define 	pb				push_back
#define 	mp				make_pair
#define 	bb 				begin()
#define     rb              rbegin()
#define 	ee 				end()
#define     ub              upper_bound
#define     lb              lower_bound
#define     present(k, m)   (m.find(k)!=m.end())?1:0
#define 	all(v) 			v.begin(), v.end()
#define     sorta(v)         sort(all(a))
#define     sortd(v)        sort(all(a), greater<ll >())
#define 	reset(a, val) 	memset(a, val, sizeof(a))
#define     pll             pair<ll, ll>
#define     vll             vector<ll>
#define     vvll            vector<vll>
#define     vpll            vector<pll>
#define 	vs 				vector<string>
#define     vc              vector<char>
#define     sqr(a)          ((a)*(a))
#define 	print1(a) 		for(auto i : a)cout<<i<<" ";cout<<"\n"
#define 	print2(a) 		for(auto i : a)cout<<i;cout<<"\n"
#define 	print3(a) 		for(auto i : a)cout<<i<<nl;
#define 	boost 			ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

// ostringstream str1;
// str1 << n;
// string tmp = str1.str();
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
 
bool compare(const pair<string, int>&a, const pair<string, int>&b){ return a.second<b.second; }

bool compare_float(double x, double y){
    return fabs(x - y) < DBL_EPSILON;
}

double logn(double n, double r) { return (n > r - 1) ? 1 + logn(n / r, r) : 0; }
 
// vll pwx(11);
// void cal(ll x){ pwx[0] = 1; rep(i, 1, 11)pwx[i] = x*pwx[i-1]; }
 
/* ################################################################ */

#define space 200005

void solve() {
  ll n;cin >> n;

  vll a(n), b(n);

  for(auto &i : a) cin >> i;

  b = a;

  for(ll i =  n - 2 ; i >= 0 ; i--) {
    a[i] += a[i+1];
    a[i] %= mod;
  }

  ll ans = 0;

  for(ll i = 0 ; i < n-1 ; i++) {
    ans += (b[i] * a[i+1]) % mod;
    ans %= mod;
  }

  cout << ans << nl;


}

 
int main(){
  // boost;
  // cal(1);

  // // For getting input from input.txt file 
  // freopen("timber_input.txt", "r", stdin); 

  // // Printing the Output to output.txt file 
  // freopen("output.txt", "w", stdout);


  int t = 1, k = 1;
  // cin>>t;
  while(t--){
      // cout<<"Case #"<<k<<": ";
      solve();
      k++;
  }
}