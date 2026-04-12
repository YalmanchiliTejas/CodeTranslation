#include <algorithm>
#include <array>
#include <bitset>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct BoolName : numpunct<char> {
  string t, f;
  BoolName (string t = "Yes", string f = "No") : t(t), f(f) {}
  string do_truename() const {return t;}
  string do_falsename() const {return f;}
};

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15) << boolalpha;
    cout.imbue(locale(cout.getloc(), new BoolName));
  }
} initializer;

template<typename T> istream& operator>>(istream &s, vector<T> &v) {
  for (T &t : v) s >> t;
  return s;
}

template<typename T> ostream& operator<<(ostream &s, const vector<T> &v) {
  for (const T &t : v) s << t << endl;
  return s;
}

void set_bool_name(string t, string f) {
  cout.imbue(locale(cout.getloc(), new BoolName(t, f)));
}

template<typename T> string to_string(const T& v) {
  string str;
  for (const auto& i : const_cast<T&>(v)) str += ' ' + to_string(i);
  return str.substr(min(1, int(str.size())));
}

template<> string to_string<string>(const string& v) {return v;}

#ifdef __MINGW32__

template<> string to_string<int>(const int& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<int64_t>(const int64_t& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<unsigned int>(const unsigned int& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<unsigned int64_t>(const unsigned int64_t& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<float>(const float& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<double>(const double& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

template<> string to_string<long double>(const long double& v) {
  stringstream ss;
  ss << v;
  return ss.str();
}

#endif

template<typename T> string join(const T &v, char delim = ' ') {
  string res;
  for (const auto& s : v) res += delim + to_string(s);
  return res.substr(1);
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  deque<int> b;
  cin >> a;
  for (int i = 0; i < n; ++i) {
    if (i % 2 == 0) b.emplace_back(a[i]);
    else b.emplace_front(a[i]);
  }
  if (n % 2) reverse(b.begin(), b.end());
  cout << join(b) << endl;
}

