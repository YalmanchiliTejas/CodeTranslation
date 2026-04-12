#include <bits/stdc++.h>
#define pb push_back
#define fr first
#define sc second
#define mk make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const double eps = 0.000000001;
const int MOD = 1000000009;
const int N = 100005;
int main()
{
      int a, b, c;
      cin >> a >> b >> c;
      a *= 100;
      a += c + b * 10;
      if (a % 4 == 0) cout << "YES" << endl;
      else cout << "NO" << endl;
      return 0;
}




