#include "iostream"
#include "vector"
#include "string"
#include "algorithm"
#include "math.h"
#include "cstring"
#include "stack"
#include "queue"

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<ll> > mat;

int main()
{
  int n;
  cin >> n;
  string s;
  cin >> s;
  int k;
  cin >> k;
  for (int i = 0; i < n; i++)
  {
    cout << (s[i] == s[k - 1] ? s[i] : '*');
  }
  cout << "\n";
}