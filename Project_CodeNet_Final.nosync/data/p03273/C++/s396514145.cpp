#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<string> vs;
const ll mod = 1e9+7;
const ll inf = 1e17;
const int INF = 1e9;
const double PI = acos(-1);
#define fo(i, a, b) for(int i = a; i < b; i++)
#define re(i, n) fo(i, 0, n)
#define pb push_back
#define mp make_pair
#define all(s) s.begin(), s.end()
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
int main()
{
  int h, w;
  cin >> h >> w;
  vector<vc> a(h, vc(w));
  re(i, h) {
    re(j, w) {
      cin >> a[i][j];
    }
  }

  vector<vc> c(h);
  int y = 0;
  re(i, h) {
    bool white = true;
    re(j, w) {
      if(a[i][j] == '#') white = false;
    }
    if(!white) {
      re(j, w) c[y].pb(a[i][j]);
      y++;
    }
  }
  int x = 0;
  re(j, w) {
    bool white = true;
    re(i, y) {
      if(c[i][j] == '#') white = false;
    }
    if(white) {
      re(i, y) c[i][j] = 'p';
    }
  }
  re(i, y) {
    re(j, w) {
      if(c[i][j] != 'p') cout << c[i][j];
    }
    cout << endl;
  }
}
