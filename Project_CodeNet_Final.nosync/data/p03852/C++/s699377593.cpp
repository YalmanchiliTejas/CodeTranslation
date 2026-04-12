#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
  string c;
  cin >> c;
  
  if (("a" == c) || ("e" == c) || ("i" == c) || ("o" == c) || ("u" == c))
  {
    printf("vowel");
  }
  else
  {
    printf("consonant");
  }
}
