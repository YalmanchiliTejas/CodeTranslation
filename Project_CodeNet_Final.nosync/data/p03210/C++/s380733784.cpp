#include <iostream>
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
typedef pair<ll, ll> P;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<str> vs;
typedef vector<P> vp;
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
  int N;
  cin >> N;
  if(N==7 || N==5 || N == 3) print("YES");
  else print("NO");
  
  

  return 0;
}
