#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<algorithm> // sort
#include<map> // pair
#include<cmath>
#include<cstring>
#include<set>
using namespace std;
using ll = long long;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
#define rep(i, n) REP(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define MSG(a) cout << #a << " " << a << endl;
#define REP(i, x, n) for(int i = x; i < n; i++)
#define all(x) (x).begin(),(x).end()
const ll mod = 1e9+7;
const int INF = 1e9;
const ll INFLONG = 1e18;
ll sum;
ll x;
int main(){
  ll n;
  cin >> n >> x;
  ll a[n+1];//the number of p
  ll b[n+1];//the number of all
  a[0] = 1;
  b[0] = 1;
  rep(i,n){
    a[i+1] = a[i]*2+1;
    b[i+1] = b[i]*2+3;
  }
  sum = 0;
  for(int i=n;i>=0;i--){
    if(x >= b[i]){
      if(x > b[i]){
        sum++;
        x--;
      }
      sum += a[i];
      x -= b[i];
      //cout << sum << " " << x << " " << i <<  endl;
      i++;
    }else{
      x--;
    }
  }
  cout << sum;
}
