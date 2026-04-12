#include <bits/stdc++.h>

using namespace std;

#define LOG(...) fprintf(stderr, __VA_ARGS__)
//#define LOG(...)
#define FOR(i, a, b) for(int i=(int)(a); i<(int)(b); ++i)
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define EXIST(s, e) ((s).find(e)!=(s).end())
#define SORT(c) sort(ALL(c))
#define RSORT(c) sort(RALL(c))
#define SQ(n) (n) * (n)

typedef long long ll;
typedef unsigned long long ull;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
  string input;
  int R;
  cin >> input >> R;
  vi num;
  REP(i, input.length()){
    switch(input[i]) {
    case '+':
      num.push_back(-1);
      break;
    case '*':
      num.push_back(-2);
      break;
    default:
      num.push_back(input[i] - '0');
      break;
    }
  }

  int L = num[0];
  for(int i = 1; i < num.size(); i+=2) {
    if(num[i] == -1) {
      L += num[i + 1];
    }else {
      L *= num[i + 1];
    }
  }

  for(int i = 1; i < num.size(); i+=2) {
    if(num[i] == -2) {
      num[i + 1] = num[i - 1] * num[i + 1];
      num[i - 1] = 0;
      num[i] = -1;
    }
  }

  int M = num[0];
  for(int i = 1; i < num.size(); i+=2) {
      M += num[i + 1];
  }

  string result = "IMLU";
  int res = ((L==R) & 1) << 1 | (M==R);
  cout << result[res] << endl;
}