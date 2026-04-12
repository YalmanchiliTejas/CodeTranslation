#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (int)(n); i++)
#define reps(i,x) for(ll i=1;i<=(int)(x);i++)
#define rrep(i,x) for(ll i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(ll i=(int)(x);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define mp make_pair
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define mod 1000000007 
using namespace std;

int main() {
  ll a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll f = c * max(x,y)* 2;
  ll d = a*x+b*y;
  ll mn = min(x,y);
  ll e = mn * 2 * c;
  if(x > y) {
    if(a > c*2) e += c * (x -mn)*2;
    else e += a * (x -mn);
  }
  else if(x < y) {
    if(b > c*2) e += c * (y -mn)*2;
    else e += b * (y -mn);
  }
  cout << min(min(d,e),f) << endl;
}
