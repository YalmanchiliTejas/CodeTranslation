#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef pair<int,int> pii;
typedef pair<long long, int> pli;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (x).size()

ll mod = 1000000007;

ll gcd(ll a, ll b){
  if (a%b == 0)return(b);
  else return(gcd(b, a%b));
}

ll inv(ll x){
  ll res = 1;
  ll k = mod - 2;
  ll y = x;
  while(k){
    if(k&1)res = (res*y)%mod;
    y = (y*y) % mod;
    k /= 2;
  }
  return res;
}


int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x;
  cin >> x;
  if(x >= 30){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}