#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
using namespace std;
 
typedef tree<pair<long long,int>, null_type, less<pair<long long,int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;
 
#define f first
#define se second
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define all(num) num.begin(), num.end()
#define lp(i, nodess) for (int i = 0; i < nodess; i++)
#define mem(u, vis) memset(u, vis, sizeof(u))
#define X real()
#define Y imag()
#define angle(u) (atan2(u.Y, u.X))
#define vec(u, v) ((v) - (u))
//#define length(u) (hypot(u.Y , u.X))
#define normalize(u) (u) / length(u)
#define dotP(u, v) ((conj(u) * v).X)
#define crossP(u, v) ((conj(u) * v).Y)
#define same(p1, p2) (dotP(vec(p1, p2), vec(p1, p2)) < EPS)
#define lengthSqr(u) dotP(u, u)
#define rotate0(p, ang) ((p)*exp(point(0, ang)))
#define rotateA(p, ang, about) (rotate0(vec(about, p), ang) + about)
#define reflect0(vis, m) conj(vis / m) * m
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
const double PI = acos(-1.0);
const double EPS = (1e-10);
const long long int INF = 0x3f3f3f3f;
const long long mod = 1e9 + 7;
typedef long long int ll;
typedef unsigned long long ull;
typedef complex<double> point;
long long fastpow(ll nodess, ll num, ll m) {
  if (!num)
    return 1;
  if (num % 2)
    return nodess * fastpow(nodess, num - 1, m)%m;
  ll p = fastpow(nodess, num / 2, m);
  p %= m;
  p *= p;
  p %= m;
  return p;
}
 
ll my_mod(ll num, ll mod) {
  ll reto = num % mod;
  while (reto < 0)
    reto += mod;
  return reto;
}
 
ll gcd(ll u, ll v) { return !u ? v : gcd(v % u, u); }
long long dist(pair<ll, ll> u, pair<ll, ll> v) {
  return 
      abs(u.f - v.f)  + abs(u.se - v.se);
}
long long getDist(pair<ll, ll> &u, pair<ll, ll> &v) {
  return 
     (u.f - v.f)*(u.f - v.f)  + (u.se - v.se)*(u.se-v.se);
}
 
 
 
/*vector<int> ap;
int np[MX+5];
void s(){
    mem(np , 1);
    np[1] = np[0] = 0;
    for(ll i = 2 ; i*i<= MX ;i++){
        if(np[i]){
            for(ll j= i*i ; j <=MX; j+=i) np[j] = 0;
        }
    }
    int idx = 1;
    for(ll i = 2 ; i<= MX ; i++){
		if(np[i]){
			np[i] = idx;
			idx++; 
			ap.pb(i);
		}
	}
	//cout<<idx;
}*/
const int MX = 10009;

int main()
{
    IO;
	int n,m;
	cin>>n>>m;
	if(n!=m) cout<<"No";
	else cout<<"Yes";
	
	
	return 0;
}

















