#include <iostream>
#include <stack>
using namespace std;

int main(void){
  stack<char> st[101];
  char ch;
  string order;
  int n,from,to;

  cin >> n;

  while(cin >> order){

    if( order == "quit" ) break;

    else if( order == "push" ){
      cin >> to >> ch;
      st[to].push(ch);
    }

    else if( order == "pop" ){
      cin >> from;
      cout << st[from].top() << endl;
      st[from].pop();
    }

    else if( order == "move" ){
      cin >> from >> to;
      st[to].push(st[from].top());
      st[from].pop();
    }

  }

  return 0;
}
    