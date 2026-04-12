#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main(){
  string op;
  stack<char> Mt[101];
  
  while(cin >> op){
    int ID1, ID2;
    if(op == "quit") break;
    if(op == "push"){
      char tmp;
      cin >> ID1 >> tmp;
      Mt[ID1].push(tmp);
    }
    else if(op == "pop"){
      cin >> ID1;
      cout << Mt[ID1].top() << endl;
      Mt[ID1].pop();
    }
    else if(op == "move"){
      cin >> ID1 >> ID2;
      Mt[ID2].push(Mt[ID1].top());
      Mt[ID1].pop();
    }
  }
  return 0;
}