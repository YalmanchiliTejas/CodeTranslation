#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <cassert>
#include <exception>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<ll,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i=(a); i<(n); ++i)
#define rrep(i,a,n) for(ll i=(a); i>(n); --i)
#define erep(i,a,n) for(ll i=(a); i<=(n); ++i)
#define rerep(i,a,n) for(ll i=(a); i>=(n); --i)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int) x.size())
#define print(X) cout << (X) << endl
#define _ << " " <<
static const int INF = 1e+9+7;
ll a,b,c,x,y;
str s,t;
int M[100];

int main(){
  cin >> a >> b >> c >> x >> y;

  ll small = INF;
  ll tmp = INF;

  erep(i, 0, max(x,y)){
    if(x-i < 0 ){
      tmp = c*i*2 + (y-i)*b;
    }else if (y-i < 0){
      tmp = c*i*2 + (x-i)*a;
    }else{
      tmp = c*i*2 + (x-i)*a + (y-i)*b;
    }
    if(tmp < small)small = tmp;
  }

  print(small);
  return 0;
}