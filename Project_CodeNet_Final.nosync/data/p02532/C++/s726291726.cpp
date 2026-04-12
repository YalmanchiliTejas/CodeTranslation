#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
  int n, p1, p2;
  char c;
  string op;
  stack<char> mountain[100];

  cin >> n;

  for (;;) {
    cin >> op;

    if (op == "push") {
      cin >> p1 >> c;
      mountain[p1].push(c);
    } else if(op == "pop") {
      cin >> p1;
      cout << mountain[p1].top() << endl;
      mountain[p1].pop();
    } else if(op == "move") {
      cin >> p1 >> p2;
      mountain[p2].push(mountain[p1].top());
      mountain[p1].pop();
    } else if(op == "quit") {
      break;
    }
  }

  return 0;
}