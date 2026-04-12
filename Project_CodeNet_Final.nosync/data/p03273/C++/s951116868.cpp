#include <bits/stdc++.h>
using namespace std;


typedef long long ll;
typedef long double ld;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;


#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ub upper_bound
#define lb lower_bound
#define asd cout << "ok" << endl;


#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define trav(it, m) for(auto it = m.begin(); it!= m.end(); it++)

const int MOD = 1e9 + 7;
const ll INF = 1e19;
const ld PI = acos((ld)-1);
const int MX = 2e5 +5;
const char nl = '\n';


int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int r, c; cin >> r >> c;
  char a[r][c];
  for(int i = 0; i < r; i++)
    for(int j = 0; j < c; j++)
      cin >> a[i][j];
  for(int i = 0; i < r; i++){
    bool ok = 0;
    for(int j = 0 ; j < c; j++){
      if(a[i][j] == '#')
        ok = 1;
    }
    if(!ok)
    {
      for(int j = 0 ; j< c; j++)
        a[i][j] = 'x';
    }
  }

  for(int i = 0; i < c; i++){
      bool ok = 0;
    for(int j = 0 ; j < r; j++){
      if(a[j][i] == '#')
      ok =1;
    }
    if(!ok){
      for(int j = 0; j < r; j++)
      {
        a[j][i] = 'x';
      }
    }
  }

  for(int i= 0;i <r; i++){
      bool ok =0;
    for(int j=0; j < c; j++){
      if(a[i][j] != 'x')
      {
        cout << a[i][j];
        ok = 1;
      }

    }
    if(ok)
    cout << nl;
  }



  return 0;
}
