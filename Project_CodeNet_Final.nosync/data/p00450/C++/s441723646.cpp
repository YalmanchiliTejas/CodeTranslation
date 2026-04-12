#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <cstring>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
typedef pair<int, int> P;
int main()
{
  int n;
  while(cin>>n,n) {
    stack<P> st; // i, color
    int bf = -1;
    FOR(i,1,n+1) {
      int in; scanf("%d", &in);
      if(bf != in) {
        if(i % 2 == 0) {
          st.pop();
          if(st.empty()) st.push(P(1, in));
        } else {
          st.push(P(i, in));
        }
      }
      bf = in;
    }
    P p1 = P(n+1, -1), p2; // p2 . . . p1
    int ans = 0;
    while(!st.empty()) {
      p2 = st.top(); st.pop();
      if(p2.second == 0) {
        ans += p1.first - p2.first;
      }
      p1 = p2;
    }
    cout << ans << '\n';
  }
  return 0;
}