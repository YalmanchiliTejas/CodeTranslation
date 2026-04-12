#include <bits/stdc++.h>
#include <tuple>
#include <iterator>
using namespace std;
using ll = long long;
const int INF = 1000000;

int main()
{
  string s;
  auto split = [](string s, char d) {
    vector<string> elems;
    int p, cnt = 0;
    while ((p = s.find(d)) != s.npos)
    {
      elems.push_back(s.substr(0, p));
      s = s.substr(p + 1);
    }
    if (s.size())
      elems.push_back(s);
    return elems;
  };
  vector<string> ans;
  vector<string> field;
  while (cin >> s, s != "#")
  {
    vector<string> t = split(s, '/');
    field.clear();
    for (int i = 0; i < t.size(); ++i)
    {
      string tmp = "";
      for (int j = 0; j < t[i].size(); ++j)
      {
        if (t[i][j] == 'b')
          tmp += 'b';
        else
          for (int k = 0; k < t[i][j] - '0'; ++k)
            tmp += '.';
      }
      field.push_back(tmp);
    }
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string str = "";
    swap(field[a - 1][b - 1], field[c - 1][d - 1]);
    for (int i = 0; i < field.size(); ++i)
    {
      int cnt = 0;
      for (int j = 0; j < field[i].size(); ++j)
      {
        if (field[i][j] != 'b')
        {
          cnt++;
        }
        else
        {
          if (cnt != 0)
          {
            str += (char)(cnt + '0');
            cnt = 0;
          }
          str += 'b';
        }
      }
      if (cnt != 0)
        str += (char)(cnt + '0');
      str += '/';
    }
    str.pop_back();
    ans.push_back(str);
  }

  for (auto &e : ans)
    cout << e << endl;

  return 0;
}
