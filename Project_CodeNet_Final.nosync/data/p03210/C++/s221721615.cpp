#include "bits/stdc++.h"

using namespace std;
using std::vector;

#define ll long long
#define vi vector<int>
#define vl vector<long long>
#define vvi vector<vi>
#define pi  pair<int,int>
#define mp  make_pair
#define pb  push_back
#define MOD int(1e9) + 7
#define PAI  3.1415926535
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define chmax(x, y) x = max(x,y)
#define chmin(x, y) x = min(x,y)
#define pr(x) cout << x << endl
#define Endl endl
#define rep(i, n) for(int i = 0 ; i < n; i++)

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int ddx[8] = {-1,0,1,-1,1,-1,0,1};
const int ddy[8] = {-1,-1,-1,0,0,1,1,1};
const int inf = 99999999;
const ll linf = 1LL << 62;

ll gcd(ll a,ll b){
  if(a < b)swap(a , b);
  if(a % b != 0) gcd(b, a%b);
  return b;
}

ll lcm(ll a,ll b){
  if(a < b)swap(a , b);
  return (a / gcd(a , b)) * b;
}

int main(){

  int x; cin >> x;
  
  if(x == 7 or x == 5 or x == 3)
    pr("YES");
  else
    pr("NO");

  return 0;
}
