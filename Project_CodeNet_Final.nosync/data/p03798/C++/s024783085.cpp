#include <algorithm>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#include <cstdio>
#define INF 1000000000000
#define MOD 1000000007ll
#define EPS 1e-10
#define REP(i,m) for(long long i=0; i<m; i++)
#define FOR(i,n,m) for(long long i=n; i<m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define pb push_back
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef long double ld;
using namespace std;

int main() {
  int n;
  cin >> n;
  int p[n] = { };
  string s;
  cin >> s;
  p[0] = 1;
  p[1] = 1;
  FOR(i, 2, n){
    if((p[i-1] == 1) ^ (s[i-1] == 'o')) p[i] = p[i-2] * (-1);
    else p[i] = p[i-2];
  }
  if(((p[0] == 1) ^ (s[0] == 'o') ^ (p[1] == p[n-1])) && ((p[n-1] == 1) ^ (s[n-1] == 'o') ^ (p[0] == p[n-2]))){
    REP(i, n) cout << (p[i] == 1 ? 'S' : 'W');
    cout << endl;
    return 0;
  }
  p[0] = 1;
  p[1] = -1;
  FOR(i, 2, n){
    if((p[i-1] == 1) ^ (s[i-1] == 'o')) p[i] = p[i-2] * (-1);
    else p[i] = p[i-2];
  }
  if(((p[0] == 1) ^ (s[0] == 'o') ^ (p[1] == p[n-1])) && ((p[n-1] == 1) ^ (s[n-1] == 'o') ^ (p[0] == p[n-2]))){
    REP(i, n) cout << (p[i] == 1 ? 'S' : 'W');
    cout << endl;
    return 0;
  }
  p[0] = -1;
  p[1] = 1;
  FOR(i, 2, n){
    if((p[i-1] == 1) ^ (s[i-1] == 'o')) p[i] = p[i-2] * (-1);
    else p[i] = p[i-2];
  }
  if(((p[0] == 1) ^ (s[0] == 'o') ^ (p[1] == p[n-1])) && ((p[n-1] == 1) ^ (s[n-1] == 'o') ^ (p[0] == p[n-2]))){
    REP(i, n) cout << (p[i] == 1 ? 'S' : 'W');
    cout << endl;
    return 0;
  }
  p[0] = -1;
  p[1] = -1;
  FOR(i, 2, n){
    if((p[i-1] == 1) ^ (s[i-1] == 'o')) p[i] = p[i-2] * (-1);
    else p[i] = p[i-2];
  }
  if(((p[0] == 1) ^ (s[0] == 'o') ^ (p[1] == p[n-1])) && ((p[n-1] == 1) ^ (s[n-1] == 'o') ^ (p[0] == p[n-2]))){
    REP(i, n) cout << (p[i] == 1 ? 'S' : 'W');
    cout << endl;
    return 0;
  }
  cout << -1 << endl;
}