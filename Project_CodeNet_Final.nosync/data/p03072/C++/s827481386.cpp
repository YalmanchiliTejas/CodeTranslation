#include <iostream>
#include <sstream>
#include <stdio.h>
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
#include <numeric>
using namespace std;
typedef long long ll;
typedef string str;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<Pll> vp;
typedef vector<bool> vb;
#define rep(i, a, n) for (ll i = (a); i < (n); ++i)
#define rrep(i, a, n) for (ll i = (a); i > (n); --i)
#define erep(i, a, n) for (ll i = (a); i <= (n); ++i)
#define rerep(i, a, n) for (ll i = (a); i >= (n); --i)
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)x.size())
#define vec_max(V) *max_element(all(V))
#define vec_min(V) *min_element(all(V))
#define vec_sum(V) accumulate(all(V), 0LL)
#define print(X) cout << (X) << "\n"
#define _ << " " <<
#define Yes print("Yes")
#define No print("No")
static const int INF = 1e+9+7;

int main(){
  ll N;
  cin >> N;
  vll H(N);
  ll ans = 0;
  rep(i,0,N){
    cin >> H[i];
    if(H[i] == vec_max(H)) ans++;
  }
  print(ans);
 return 0;
}
