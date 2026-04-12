#include "bits/stdc++.h"

using namespace std;

#define ll long long
#define vi  vector<int>
#define vvi vector<vi>
#define pi  pair<int,int>
#define mp  make_pair
#define pb  push_back
#define MOD 1e9 + 7
#define PAI  3.1415
#define all(x) (x).begin(),(x).end()
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
#define pr(x) cout << x << endl
#define Endl endl
#define rep(i,n) for(int i = 0 ; i < n; i++)

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
const int ddx[8] = {-1,0,1,-1,1,-1,0,1};
const int ddy[8] = {-1,-1,-1,0,0,1,1,1};
const int inf = 99999999;
const ll linf = 1LL << 62;

int main(){

  int n;
  while(cin >> n , n){
    int maxa = -inf, mina = inf;
    int sum = 0;
    rep(i,n){
      int a; cin >> a;
      chmin(mina,a);
      chmax(maxa,a);
      sum += a;
    }
    cout << (sum - maxa - mina) / (n-2) << endl;
  }

  return 0;

}

