#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define rep1(i,n) for (int i = 1; i <= (n); i++)
#define repi(i,a,b) for (int i = (a); i < (b); i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vc = vector<char>;
using vvc = vector<vc>;
using vs = vector<string>;

int main() {
  int r, g, b;
  cin >> r >> g >> b;
  
  if ((r*100+g*10+b)%4 == 0) 
    cout << "YES" << endl;
  else 
    cout << "NO" << endl;
}