#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <map>
#include <time.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

#define pb push_back
#define rep(i, a, n) for(int i = (a); i < (n); i++)
#define dep(i, a, n) for(int i = (a); i >= (n); i--)
#define mod (ll)(1e9+7)
#define int ll

__attribute__((constructor))
void initial() {
  cin.tie(0);
  ios::sync_with_stdio(false);
}

signed main() {


  int x;
  cin>>x;
  if(3==x||5==x||7==x)cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
}
