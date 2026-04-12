#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for((i)=0;(i)<(n);(i)++)
#define max(a,b) ((a)>(b) ? (a) : (b))
#define min(a,b) ((a)<(b) ? (a) : (b))
typedef long long ll;
typedef long double ld;
#define MOD1 1000000007
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
int main(){
  ll n,m,k,i,j,result=0,sum=0;
  ll a[200010]={0};
  string s;
  cin >> n;
  rep(i,n){
    cin >> a[i];
    sum += a[i];
  }
  rep(i,n){
    sum -= a[i];
    result += (a[i] * (sum % MOD1)) % MOD1;
    result %= MOD1;
  }
  cout << result << endl;
  return 0;
}