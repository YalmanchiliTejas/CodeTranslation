#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <regex>
#include <numeric>
using namespace std;

/*--- Macro ---*/
#define rep(i, n) for(int i=0; i<(int)n; i++)
#define rep1(i, n) for(int i=1; i<(int)n; i++)
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()

/*---  Type ---*/
typedef long long ll;

/*--- Constants ---*/
template <typename T> const T INF = numeric_limits<T>::max() / 10;
const int MOD = (int)1e9 + 7;

// Floating
const double EPS = 1e-11;
#define EQ0(x) (abs(x) < EPS)
#define EQ(x, y) (abs(a-b) < EPS)

// Util
int max(int a, int b, int c) {return max(a, max(b, c));}
int min(int a, int b, int c) {return min(a, min(b, c));}
ll max(ll x, ll y) {return x > y ? x : y;}
ll min(ll x, ll y) {return x < y ? x : y;}
ll max(ll a, ll b, ll c) {return max(a, max(b, c));}
ll min(ll a, ll b, ll c) {return min(a, min(b, c));}

// How to use 「map」
/*
  - 宣言
    map<{key_type}, {value_type}> salary;
  - 要素の挿入
    salary["Alice"] = 1000;
  - 要素の取得 O(logn)
    salary.at("Alice");
  - 要素の削除
    salary.erase("Alice");
  - キー検索
    salary.find("Alice"); -> true
    salary.find("Bob");   -> false
  - イテレーション
    for(auto& [key, value] : salary) {...}
 */
// -------------------------------------


// How to use 「lower_bound」, 「upper_bound」
/*
  vector<int> a = {1, 2, 3, 4, 5};
  auto iter1 = lower_bound(all(a), 3);  <- 第二引数「以上」の最小イテレータが返る
  auto iter2 = upper_bound(all(a), 3);  <- 第二引数「より大きい」最小のイテレータが返る
 */
// -------------------------------------


// How to use 「struct sort」
/*
  struct Person {
    string name;
    int age;

    Person(string _name, int _age) {
      name = _name;
      age = _age;
    }

    bool operator<(const Person &another) const {
      return age < another.age;
    }
  };

  vector<Person> people;
  people.pb(Person("Alice", 20));
  people.pb(Person("Bob", 19));
  people.pb(Person("John", 40));
  people.pb(Person("Chris", 30));
  sort(all(people));
 */
 // -------------------------------------

// -------------------------------------------------------------------------------------

ll combination(ll n, ll r)
{
    if (r == 0 || r == n)
        return (1);
    else if (r == 1)
        return (n);
    return (combination(n - 1, r - 1) + combination(n - 1, r));
}

ll perm(ll n) {
  ll ret = 1;
  rep1(i, n+1) {
    ret *= i;
  }
  return ret;
}

ll solve(int k, string n) {
  if (k == 0) return 1;
  if (n.length() == 0)return 0;

  ll p = n[0] - '0';

  string nsub = n.substr(1);

  // 1文字目が0
  if (p == 0) {
    return solve(k, nsub);
  }

  // 1文字目が0の場合の計算
  // 残りの桁から0以外の数字をk-p個選ぶ
  ll rest_len = nsub.length();
  ll ans1 = 0;
  if (rest_len >= k) {
    ans1 = ((pow(9, k) * combination(rest_len, k)));
  }

  if (p == 1) {
    return ans1 + solve(k-1, nsub);
  }

  // 1文字目が0以外の場合の計算
  ll ans2 = 0;
  if (rest_len >= k-1) {
    ans2 = (p-1) * ((pow(9, k-1) * combination(rest_len, k-1)));
  }

  return ans1 + ans2 + solve(k-1, nsub);
}


int main() {
  string n;
  int k;
  cin >> n >> k;

  cout << solve(k, n) << endl;

  return 0;
}