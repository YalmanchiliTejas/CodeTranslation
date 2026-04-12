#define  _USE_MATH_DEFINES

#define  rep(i, n) for(int i = 0; i < n; i++)
#define  repx(i, a, n) for(int i = a; i < n; i++)
#define  loop while(1)
#define  lli long long int
 
#include <iostream>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <utility>
#include <set>

using namespace std;

int main() {

  string str;
  cin >> str;

  int n;
  cin >> n;

  stack<int> st;
  st.push((int)(str[0] - '0'));
  int tmp = 0;

  int ans1 = 0;
  int ans2 = (int)(str[0] - '0');

  char opr;
  int  num;

  for (int i = 1; i < str.size() / 2 + 1; i++) {
    opr = str[2 * i - 1];
    num = (int)(str[2 * i] - '0');
    if (opr == '+') {
      st.push(num);
      ans2 += num;
    }
    else {
      tmp = st.top();
      st.pop();
      st.push(tmp * num);
      ans2 *= num;
    }
  }
  while (st.size()) {
    ans1 += st.top();
    st.pop();
  }

  if (n == ans1 && n == ans2) cout << 'U' << endl;
  else if (n == ans1) cout << 'M' << endl;
  else if (n == ans2) cout << 'L' << endl;
  else cout << 'I' << endl;

  return 0;
}

