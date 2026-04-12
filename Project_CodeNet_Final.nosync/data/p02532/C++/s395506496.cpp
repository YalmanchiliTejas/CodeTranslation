#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
string s;
stack<char> st[111];
int main(void){
  int a;
  cin >> a;
  while(cin >> s && s != "quit"){
    if(s == "push"){
      int n;
      char c;
      cin >> n >> c;
      st[n].push(c);
    }else if(s == "pop"){
      int n;
      cin >> n;
      cout << st[n].top() << endl;
      st[n].pop();
    }else{
      int n,m;
      cin >> n >> m;
      st[m].push(st[n].top());
      st[n].pop();
    }
  }
}