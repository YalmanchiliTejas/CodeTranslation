#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;
int N;
string s;

void print_animal(vector<bool> is_sheep)
{
  rep(i, N)
  {
    if (is_sheep[i])
      cout << 'S';
    else
      cout << 'W';
  }
  cout << endl;
}

bool is_ok(vector<bool> is_sheep)
{
  rep(i, N - 1)
  {
    if (s[i + 1] == 'o' && is_sheep[i + 1])
      is_sheep.push_back(is_sheep[i]);
    else if (s[i + 1] == 'x' && is_sheep[i + 1])
      is_sheep.push_back(!is_sheep[i]);
    if (s[i + 1] == 'o' && !is_sheep[i + 1])
      is_sheep.push_back(!is_sheep[i]);
    if (s[i + 1] == 'x' && !is_sheep[i + 1])
      is_sheep.push_back(is_sheep[i]);
  }

  bool ok = true;
  rep(i, N)
  {
    int i_pre = (i + N - 1) % N;
    int i_next = (i + 1) % N;

    if ((is_sheep[i_pre] && is_sheep[i_next]) || (!is_sheep[i_pre] && !is_sheep[i_next]))
    {
      if (s[i] == 'o' && is_sheep[i])
        continue;
      else if (s[i] == 'x' && !is_sheep[i])
        continue;
    }
    else if ((!is_sheep[i_pre] && is_sheep[i_next]) || (is_sheep[i_pre] && !is_sheep[i_next]))
    {
      if (s[i] == 'o' && !is_sheep[i])
        continue;
      else if (s[i] == 'x' && is_sheep[i])
        continue;
    }

    ok = false;
    break;
  }

  if (ok)
    print_animal(is_sheep);

  return ok;
}

int main()
{
  cin >> N >> s;
  if (!is_ok({true, true}) && !is_ok({true, false}) && !is_ok({false, true}) && !is_ok({false, false}))
    cout << -1 << endl;

  return 0;
}