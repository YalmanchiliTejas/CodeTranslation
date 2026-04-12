#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <utility>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const double EPS = 1e-9;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  char c;
  cin>>c;
  if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
    cout << "vowel" << endl;
  } else {
    cout << "consonant" << endl;
  }

  return 0;
}
