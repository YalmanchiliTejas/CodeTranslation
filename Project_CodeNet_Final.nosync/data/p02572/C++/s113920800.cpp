#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(int x, int y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<int>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  ll p=1000000007;
  int n;
  cin >> n;
  ll o=0;
  ll b=0;
  rep(i,n){
    ll a;
    cin >> a;
    o=(o+a*a)%p;
    b=(b+a)%p;
  }
  b=(b*b+p-o)%p;
  if(b%2==0){
    cout << b/2 << endl;
  }
  else cout << (b+p)/2 << endl; 
}
