#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)

/* short names and const
using ll = long long;
using vll = vector<long long>;
using df = vector<vector<long long>>;
df data(n, vector<long long>(m));
const int MOD = 1e9 + 7;
const long long INF = 1e18;
*/

/* Boost!
#include <boost/algorithm/string/classification.hpp> // is_any_of
#include <boost/algorithm/string/split.hpp>
using boost::algorithm::split; // split(result, s, boost::is_any_of(","));
#include <boost/algorithm/string/join.hpp>
using boost::algorithm::join; // string s = join(arr, "");
#include <boost/algorithm/string/replace.hpp>
using boost::algorithm::replace_all; // replace_all(s, "AtCoder", "A");
#include <boost/range/algorithm.hpp> // boost::sort(arr)
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
*/

/* print(arr)
template <class T>
void print(vector<T> &vec) {
  for (auto& a : vec) {
    cout << a;
    if (&a != &vec.back()) cout << " ";
  }
  cout << endl;
}
*/

/* fast cin and precise cout
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  getline(cin, s);
  cout << fixed << setprecision(15);
*/

/* sum function
int sum(vector<int> &arr) {
  int res = accumulate(arr.begin(), arr.end(), 0);
  return res;
}
*/

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  x -= (y + 2 * z);
  cout << 1 + (x / (y + z)) << endl;
}
