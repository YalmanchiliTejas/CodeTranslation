#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;
stack<char> s[100];
int main(void)
{
  queue<char> ans;
  int m;
  string c="";
  int a1,a2;
  char a2c;
  cin>>m;
  while(c!="quit")
  {
    cin>>c;
    if(c=="push")
    {
      cin>>a1;
      cin>>a2c;
      s[a1-1].push(a2c);
    }else if(c=="pop")
    {
      cin>>a1;
      ans.push(s[a1-1].top());
      s[a1-1].pop();
    }else if(c=="move")
    {
      cin>>a1;
      cin>>a2;
      s[a2-1].push(s[a1-1].top());
      s[a1-1].pop();
    }
  }
  while(!ans.empty()){
    cout<<ans.front()<<endl;
    ans.pop();
  }
  return 0;
}