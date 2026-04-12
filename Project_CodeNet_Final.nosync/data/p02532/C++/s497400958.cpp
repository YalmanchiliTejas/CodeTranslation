#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int n;
stack<char> v[100];
string op;
char c;
int p, p1, p2;

int main() {
  cin >> n;
  while(cin >> op && op != "quit") {
    if(op == "push") {
      cin >> p >> c;
      v[p-1].push(c);
    } else if(op == "pop") {
      cin >> p;
      cout << v[p-1].top() << endl;
      v[p-1].pop();
    } else {
      cin >> p1 >> p2;
      v[p2-1].push(v[p1-1].top());
      v[p1-1].pop();
    }
  }
  return 0;
}