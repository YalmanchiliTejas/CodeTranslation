#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int n1, n2;
  string str;
  stack<char> block[100];
  char c;

  cin >> n1;

  while(1) {
    cin >> str;

    if(str == "quit") {
      break;
    } else if(str == "push") {
      cin >> n1 >> c;
      block[n1-1].push(c);
    } else if(str == "pop") {
      cin >> n1;
      cout << block[n1-1].top() << endl;
      block[n1-1].pop();
    } else {
      cin >> n1 >> n2;
      c = block[n1-1].top();
      block[n1-1].pop();
      block[n2-1].push(c);
    }
  }

  return 0;
}