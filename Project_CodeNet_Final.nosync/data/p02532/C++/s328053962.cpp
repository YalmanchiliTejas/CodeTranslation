#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>
#include <cmath>
#include <stack>
using namespace std;

 
int main()
{
  int n;
  cin >> n;
  stack<string> stck[n];
  string s;
  while(cin >> s, s != "quit") {    
    int p1;
    cin >> p1;
    if(s == "push") {
      string c;
      cin >> c;
      stck[p1-1].push(c);
    }
    else if(s == "pop"){
      cout << stck[p1-1].top() << endl;
      stck[p1-1].pop();
    }
    else {
      int p2;
      cin >> p2;
      stck[p2-1].push(stck[p1-1].top());
      stck[p1-1].pop();
    }
  }

  return 0;
}