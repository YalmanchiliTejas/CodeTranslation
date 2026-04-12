#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}


int main(){

  int x;
  cin >> x;
  if(x>=30){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }


  return 0;
}