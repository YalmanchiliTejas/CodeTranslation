#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>

#define rep(i, j) for(int i = 0; i <(j); i++)

using namespace std;

int main(void)
{
  stack<char> s[101];
  string d;
  char c;
  int n, n2;
  int mn;
  cin >> mn;
  
  while((cin >> d), d != "quit"){
    if (d == "push"){
      cin >> n;
      cin >> c;
      s[n].push(c);
    }
    else if(d == "pop"){
      cin >> n;
      printf("%c\n", s[n].top());
      s[n].pop();
    }
    else if(d == "move"){
      cin >> n;
      cin >> n2;
      s[n2].push(s[n].top());
      s[n].pop();
    }
  }
  
  return 0;
}