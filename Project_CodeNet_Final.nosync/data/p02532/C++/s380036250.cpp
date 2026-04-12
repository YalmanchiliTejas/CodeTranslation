#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
  int n, p, q;
  string order, color;

  cin >> n;
  vector<stack<string> > st(n);
  
  while(true){
    cin >> order;
    if(order == "quit") break;
    else if(order == "push"){
      cin >> p;
      cin >> color;
      st[p-1].push(color);
    }
    else if(order == "pop"){
      cin >> p;
      cout << st[p-1].top() << endl;
      st[p-1].pop();
    }
    else if(order == "move"){
      cin >> p;
      cin >> q;
      st[q-1].push(st[p-1].top());
      st[p-1].pop();
    }
  }
  return 0;
}