#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repr(i, n) for (int i = (n); i >= 0; --i)
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define FORR(i, m, n) for (int i = (m); i >= (n); --i)
#define ifaxb(a, x, b) if (a < x && x < b) // 比較は昇順
#define vi vector<int>
#define vii vector<vi>
#define vs vector<string>
#define vss vector<vs>
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define pq priority_queue
#define ipair pair<int, int>
#define spair pair<string, string>
#define lpair pair<LL, LL>
#define MP make_pair
#define MM multimap
#define PB push_back
#define INF 2147483647
#define _INF -2147483647
#define pi 3.1415926536
#define MAXN 100004
using namespace std;
typedef long long ll;

int main()
{
  int X;
  cin >> X;
  if (1 < X && X < 9 && X % 2 != 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
