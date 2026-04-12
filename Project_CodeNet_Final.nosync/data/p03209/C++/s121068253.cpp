#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define REP(i,s,n) for(int i = s; i < n; i++)
#define INF 1000000007
typedef long long ll;
using namespace std;
using Graph = vector<vector<int>>;
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return (a * b) / gcd(a,b); }
ll ceil(const ll a, const ll b) { return (a + b - 1) / b; }
ll f[100],num[100];
ll solve(ll n,ll b){
  if(b == 0)return 0;
  if(n == 0)return 1;
  if(b >= 2 * num[n - 1] + 2)return f[n];
  else if(b >= num[n - 1] + 2){
    ll tmp = b - (num[n - 1] + 2);
    ll res = f[n - 1] + 1 + solve(n - 1,tmp);
    return res;
  }
  else{
    ll tmp = b - 1;
    return solve(n - 1,tmp);
  }
}
int main(){
  ll n,x;
  cin >> n >> x;
  f[0] = num[0] = 1;
  rep(i,50){
    f[i + 1] = 2 * f[i] + 1;
    num[i + 1] = 2 * num[i] + 3;
  }
  cout << solve(n,x) << endl;
  return 0;
}
