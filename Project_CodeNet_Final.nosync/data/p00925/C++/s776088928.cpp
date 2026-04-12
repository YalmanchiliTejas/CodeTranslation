#include <algorithm>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define EPS 1e-10
#define INF 1000000000
#define mp make_pair
#define pb push_back

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int,int> pii;
typedef long long ll;

ll calcWithMFR(string formula) {
  ll first_num = 1, second_num = 0;
  for (int i = 0; i < formula.size(); i++) {
    if (formula[i] == '*') {
      first_num *= second_num;
      second_num = 0;
      continue;
    } else if (formula[i] == '+') {
      return first_num * second_num + calcWithMFR(formula.substr(i+1));
    }
    int num = (int)(formula[i] - '0');
    if (second_num == 0) {
      second_num = num;
    } else {
      second_num = second_num * 10 + num;
    }
  }
  first_num *= second_num;
  return first_num;
}

ll calcWithLRR(string formula) {
  ll last_num = 0;
  for (int i = formula.size() - 1; i >= 0; i--) {
    if (formula[i] == '*') {
      return calcWithLRR(formula.substr(0, i)) * last_num;
    } else if (formula[i] == '+') {
      return calcWithLRR(formula.substr(0, i)) + last_num;
    }
    int num = (int)(formula[i] - '0');
    last_num += pow(10.0, (double)(formula.size() - i - 1)) * num;
  }
  return last_num;
}

int main() {
  string formula;
  cin >> formula;
  ll a;
  cin >> a;
  if (calcWithMFR(formula) == a && calcWithLRR(formula) == a) {
    cout << "U" << endl;
  } else if (calcWithMFR(formula) == a) {
    cout << "M" << endl;
  } else if (calcWithLRR(formula) == a) {
    cout << "L" << endl;
  } else {
    cout << "I" << endl;
  }
}