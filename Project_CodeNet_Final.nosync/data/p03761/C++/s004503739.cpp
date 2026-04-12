#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  int n;
  int MAX_N = 50;
  int MAX_S = 50;
  cin >> n;
  vector<string> str(n);
  for(int i = 0; i < n; i++)
    cin >> str[i];

  char ch[MAX_N][MAX_S + 1] = {};
  for(int i = 0; i < n; i++)
    str[i].copy(ch[i], str[i].size());

  char alpha = 'a';
  do
  {
    bool search;
    for(int i = 0; i < n; i++)
    {
      search = false;
      for(int j = 0; ch[i][j] != '\0'; j++)
      {
        if(ch[i][j] == alpha)
        {
          ch[i][j] = '-';
          search = true;
          break;
        }
      }
      if(!search)
        break;
    }
    if(search)
      cout << alpha << flush;
    else
      alpha++;
  }while(alpha <= 'z');

  return 0;
}
