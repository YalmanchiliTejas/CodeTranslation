#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(int)(n); i++)
#define rep1(i, n) for(int i=1; i<=(int)(n); i++)
#define rep2(i, n, m) for(int i=n; i<=m; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> wi;
typedef vector<ll> vl;
const ll inf=1LL << 60;
const ll MOD=1e9+7;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x, y, z;
  cin >> x >> y >> z;

  cout << (x-z)/(y+z) << endl;

  return 0;
}