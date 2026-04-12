#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<iomanip>
#include<set>
using namespace std;
#define FOR(i, a, b) for(int i=(a); i<(b);  i++)
#define REP(i, n)    for(int i=0;   i<(n);  i++)
#define REP1(i, n)   for(int i=1;   i<=(n); i++)
#define pb push_back
#define mp make_pair
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define EPS 1e-7
#define ALL(obj) (obj).begin(), (obj).end()
using ul    = unsigned long;
using ll    = long long;
using ld    = long double;
using vint  = vector<int>;
using vll   = vector<ll>;
using pint  = pair<int, int>;
using pll   = pair<ll, ll>;
using vpint = vector<pint>;
using vpll  = vector<pll>;
const int INF = (int)1e9 + 1;
const int MOD = (int)1e9 + 7;

int n, k;
string s;

int main(void)
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  scan(n); scan(s); scan(k);
//  vint s(n);
  REP(i, n){
    if(s[i]!=s[k-1]){ s[i]='*'; }
  }

  cout << s << endl;

  return 0;
}
