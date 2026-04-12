#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int N;
  cin >> N;
  multiset<int> ans;
  rep(i, N)
  {
    int A;
    cin >> A;
    if (i == 0)
      ans.insert(A);
    else if (*ans.begin() >= A)
      ans.insert(A);
    else
    {
      auto it = ans.lower_bound(A);
      it--;
      ans.erase(it);
      ans.insert(A);
    }
  }
  cout << ans.size() << endl;
  return 0;
}