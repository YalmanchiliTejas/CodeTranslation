//code by lynmisakura.wish to be accepted!
/****************************/
#include<bits/stdc++.h>
using namespace std;
/***************************/
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;
 
const long long INF = 1LL << 55;
 
#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )
 
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }
 
#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
long long f(long long x){
   ll a1 = (x+6)*(x+5)*(x+4)/6;
   ll a2 = (x+3)*(x+2)*(x+1)*x/24;
   ll m = 35;
   return (a1 * a2) / 35;
}

int main(void){
   long long k;cin >> k;
   vector<ll> c(605);
   // cout << f(1) << endl;
   for(ll i = 605;i >= 1;i--){
      c[i - 1] = k / f(i);
      k %= f(i);
   }
   
   ll count = 0;
   for(ll i = 0;i < 605;i++){
      cout << "FESTIVA";
      for(int j = 0;j < c[i];j++)cout << "L";
      //count += 6 + c[i];
   }
   //cout << count << endl;
   printf("\n");
   return 0;
}
