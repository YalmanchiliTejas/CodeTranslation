#include <iostream>
#include <algorithm>
#include <array>
#include <atomic>
#include <bitset>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define rep(i, a, n) for(int i = a; i <= n; i++)

template<class T, class U> inline bool chmax(T& a, U b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class U> inline bool chmin(T& a, U b) { if (a > b) { a = b; return 1; } return 0; }

// 第一引数 == 第二引数 ? true : false
template<class T, class U>
bool check(T first, U second) {
    return (first == second);
}

// 約数列挙
vector<int64_t> divisor(int64_t n) {
  vector<int64_t> ret;
  for(int64_t i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.push_back(i);
      if(i * i != n) ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}


// 数字和
template<class T>
T digitSum(T num) {
    T dig;
    T sum = 0;
    while (num) {
        dig = num % 10;
        sum += dig;
        num /= 10;
    }
    return sum;
}

string background_black(string s) { return "\x1b[40m" + s; }
string background_red(string s) { return "\x1b[41m" + s + "\x1b[40m"; }
string background_green(string s) { return "\x1b[42m" + s + "\x1b[40m"; }
string background_yellow(string s) { return "\x1b[43m" + s + "\x1b[40m"; }
string background_bleu(string s) { return "\x1b[44m" + s + "\x1b[40m"; }
string background_white(string s) { return "\x1b[47m" + s + "\x1b[40m"; }

string black(string s) { return "\x1b[30m" + s + "\x1b[37m"; }
string red(string s) {return "\x1b[31m" + s + "\x1b[37m"; }
string green(string s) { return "\x1b[32m" + s + "\x1b[37m"; }
string yellow(string s) { return "\x1b[33m" + s + "\x1b[37m"; }
string blue(string s) { return "\x1b[34m" + s + "\x1b[37m"; }
string white(string s) { return "\x1b[37m" + s + "\x1b[37m"; }

const int ten = 10;
const int hundred = 100;
const int thousand = 1000;

typedef long long ll;
typedef unsigned long long ull;

string tolower(string s) {
  string c;
  for (int i = 0; i < s.size(); i++) {
    if ((s[i] >= 'A') && (s[i] <= 'Z')) {
        c.push_back((s[i] + 0x20));
    } else {
        c.push_back(s[i]);
    }
  }
  return c;
}
#include <cstdlib>
string solve() {
  string str = "";
// int->string: to_string, string->int: stoi
//=============================================================================


  int n, m;
  cin >> n >> m;
  if (n == m) {
    str += "Yes";
  } else {
    str += "No";
  }


//=============================================================================
  return str;
}

int main() {	
  std::cin.tie(nullptr);
	std::ios_base::sync_with_stdio(false);
  cout << solve() << endl;
}