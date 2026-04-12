#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int main()
{
  string s;
  int n;
  cin >> s >> n;
  stack<int> a;
  for(int i = 0; i < (int)s.size(); i++){
    if(isdigit(s[i])){
      a.push(s[i]-'0');
    }else if(s[i] == '*'){
      int x = a.top() * (s[++i] - '0');
      a.pop();
      a.push(x);
    }
  }
  int x = 0;
  while(!a.empty()){
    x += a.top();
    a.pop();
  }
  for(int i = 0; i < (int)s.size(); i++){
    if(isdigit(s[i])){
      a.push(s[i]-'0');
    }else if(s[i] == '*'){
      int x = a.top() * (s[++i] - '0');
      a.pop();
      a.push(x);
    }else if(s[i] == '+'){
      int x = a.top() + (s[++i] - '0');
      a.pop();
      a.push(x);
    }
  }
  int y = a.top();
  if(n == x && n == y)
    cout << 'U';
  else if(n == x)
    cout << 'M';
  else if(n == y)
    cout << 'L';
  else
    cout << 'I';
  cout << endl;
}