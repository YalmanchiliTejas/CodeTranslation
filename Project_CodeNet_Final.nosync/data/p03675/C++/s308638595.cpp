#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define FORR(i,a,b) for (int i=(a);i>=(b);i--)
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef set<int> si;
const int inf = 1e9;
const int mod = 1e9+7;
int a[200000];
vi b[2];
int n;

main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n;
  int d;
  FOR(i, 0, n){
    cin >> d;
    b[(i+1)%2].pb(d);
  }
  reverse(b[n%2].begin(), b[n%2].end());
  for(vi::iterator itr=b[n%2].begin(); itr != b[n%2].end(); itr++){
    cout << (*itr) << " ";
  }
  int s = b[(n+1)%2].size();
  FOR(i, 0, s){
    cout << b[(n+1)%2][i];
    cout << (i < s - 1 ? " " : "\n");
  }
}
