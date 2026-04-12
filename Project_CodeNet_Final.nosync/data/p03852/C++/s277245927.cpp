#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
 
int main() {
  char a;
  cin >> a;
  if (a == 'a' || a == 'i' || a == 'u' || a == 'e' || a== 'o') {
    cout << "vowel";
  } else {
    cout << "consonant";
  }
}