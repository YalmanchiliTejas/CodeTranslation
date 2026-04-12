#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define call(x) (x).cbegin(), (x).cend()
#define pb push_back
const double PI = acos(-1);
const long long INF = (1LL << 60);
ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}
ll stringcount(string s, char c){return count(s.cbegin(), s.cend(), c);}
bool isInteger(double x){return floor(x) == x;}
ll ceil(const ll a, const ll b){return ((a)+(b)-1)/b;}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;

  ll ans = 0;
  if(a+b >= c*2){
    ans += min(x, y) * c * 2;
    ll amari = max(x,y) - min(x,y);
    if(x > y) ans = min(ans+amari*a, ans+amari*c*2);
    else ans = min(ans+amari*b, ans+amari*c*2);
  }else{
    ans += a*x + b*y;
  }
  cout << ans << endl;
  return 0;
}