#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <set>
using namespace std;
typedef long long int ll;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define yes cout << "yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define no cout << "no" << endl

const int INF = 1001001001;
const int mod = 1000000007;
#define PI 3.14159265359;

void P(int x) {cout << x << endl;}
void P(long x) {cout << x << endl;}
void P(double x) {cout << x << endl;}
void P(ll x) {cout << x << endl;}
void P(string x) {cout << x << endl;}
void P(char x) {cout << x << endl;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  int h, w;
  cin >> h >> w;
  char masu[h][w];
  rep (i, h) {
    rep (j, w) {
      cin >> masu[i][j];
    }
  }

  int tate[w];
  int yoko[h];
  rep (i, h) {
    int flag = 0;
    rep (j, w) {
      if (masu[i][j] == '#') {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      yoko[i] = 1;
    } else {
      yoko[i] = 0;
    }
  }

  rep (j, w) {
    int flag = 0;
    rep (i, h) {
      if (masu[i][j] == '#') {
        flag = 1;
        break;
      }
    }
    if (flag == 0) {
      tate[j] = 1;
    } else {
      tate[j] = 0;
    }
  }

  rep (i, h) {
    if (yoko[i] == 1) continue;
    rep (j, w) {
      if (tate[j] == 1) continue;
      cout << masu[i][j];
    }
    cout << endl;
  }



  return 0;
}

