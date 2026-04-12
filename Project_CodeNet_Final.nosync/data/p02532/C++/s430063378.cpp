#include<bits/stdc++.h>
using namespace std;
int main(){
  stack< char > st[1000];
  int n;
  string s;
  cin >> n;
  while(cin >> s, s != "quit"){
    if(s == "pop"){
      int a;
      cin >> a;
      cout << st[a - 1].top() << endl;
      st[a - 1].pop();
    }else if(s == "move"){
      int a, b;
      cin >> a >> b;
      st[b - 1].push(st[a - 1].top());
      st[a - 1].pop();
    }else{
      int a;
      char c;
      cin >> a >> c;
      st[a - 1].push(c);
    }
  }
}