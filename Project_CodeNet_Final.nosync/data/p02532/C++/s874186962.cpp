#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void){

  stack <char> st[101];
  int p1,p2;
  char c;
  string s;
  int n;

  cin >> n;

  while(1){

    cin >> s;
    if( s == "quit"){
      break;
    }
    else if( s == "push"){
      cin >> p1 >> c;
      st[p1].push(c);
    }
    else if( s == "move"){
      cin >> p1 >> p2;
      st[p2].push( st[p1].top() );
      st[p1].pop();
    }
    else if( s == "pop"){
      cin >> p1;
      cout << st[p1].top() << endl;
      st[p1].pop();
    }
  }
  return 0;
}