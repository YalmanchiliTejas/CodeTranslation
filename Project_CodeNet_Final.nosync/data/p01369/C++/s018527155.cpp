#include <bits/stdc++.h>
using namespace std;

int main()
{
  string l = "QWERTASDFGZXCVB";
  string r = "YUIOPHJKLNM";
  bool f[26];

  for (int i = 0; i < l.size(); ++i) f[l[i] - 'A'] = true;
  for (int i = 0; i < r.size(); ++i) f[r[i] - 'A'] = false;

  string str;
  while (cin >> str, str[0] != '#'){
    bool h = f[str[0] - 'a'];
    int cnt = 0;
    for (int i = 1; i < str.size(); ++i){
      if (h != f[str[i] - 'a']) cnt++;
      h = f[str[i] - 'a'];
    }
    cout << cnt << endl;
  }
}