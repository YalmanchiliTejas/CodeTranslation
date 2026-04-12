#include<string>
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
char a[101][101];
int b[101];
int c[101];

int main() {
  int h,w;
  cin >> h >> w;
  rep(i, h){
    rep(j, w){
      cin >> a[i][j];
    }
  }
  rep(i, h){
    bool f = true;
    rep(j, w) {
      if(a[i][j] == '#') f = false;
    }
    if(f)
      b[i] = 1;
  }
  rep(j, w) {
    bool f = true;
    rep(i, h){
      if(a[i][j] == '#') f = false;
    }
    if(f)
      c[j] = 1;
  }
  rep(i, h){
    bool f =false;
    rep(j, w){
      if(!b[i] && !c[j]){
        cout << a[i][j];
        f = true;
      }
    }
      if(f)
        cout << endl;
  }
}
