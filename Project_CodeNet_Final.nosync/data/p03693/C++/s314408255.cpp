#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define itn long long

typedef long long ll;
typedef pair<ll,ll> p;


int main()
{
  int r, g, b;
  cin >> r >> g >> b;
  if((r*100 + g*10 + b) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;

}