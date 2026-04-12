#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <utility>
#include <typeinfo>
#include <string>
#include <sstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<ll> VL;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i < (int)(n); i++)

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  int K, N;

  cin >> N >> s >> K;
  char target = s[K-1];
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] != target) s[i] = '*';
  }
  cout << s << endl;
}
