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
typedef unsigned long long ull;
typedef pair<string,ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<P> vp;
#define rep(i,a,n) for(ll i = (a);i < (n);i++)
#define per(i,a,n) for(ll i = (a);i > (n);i--)
#define lep(i,a,n) for(ll i = (a);i <= (n);i++)
#define pel(i,a,n) for(ll i = (a);i >= (n);i--)
#define clr(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz size()
#define print(X) cout << (X) << endl
const ll INF = 1e+9+7;
ll n,m,l;
string s,t;
ll d[100000],dp[100][100];
int g[10][10];

int check(int f){
  l = 0;
  ll ans = 0;
  rep(i,0,n)if(d[i])l++;
  if(l == n)return 1;
  rep(i,0,n){
    if(!g[f][i] || d[i])continue;
    d[i] = 1;
    ans += check(i);
    d[i] = 0;
  }
  return ans;
}

int main(){
  cin >> n >> m;
  rep(i,0,m){
    int a,b;
    cin >> a >> b;
    a--;b--;
    g[a][b] = g[b][a] = 1;
  }
  clr(d,0);
  d[0] = 1;
  print(check(0));
  return 0;
}