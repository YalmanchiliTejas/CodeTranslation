#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    string s;
    cin >> s;
  
  	bool flag = false;
  	if (s[0] == s[1])
    {
      if (s[0] == s[2])
      {
        flag = true;
      }
    }

    if (true == flag)
    {
      printf("No");
    }
    else
    {
      printf("Yes");
    }

    return 0;
}