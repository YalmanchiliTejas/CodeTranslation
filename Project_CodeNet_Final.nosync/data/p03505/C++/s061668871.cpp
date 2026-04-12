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
#include <deque>
using namespace std;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
typedef long long ll;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll K, A, B;
  cin >> K >> A >> B;
  if(K <= A) cout << 1 << endl;
  else if(A <= B) cout << -1 << endl;
  else {
    cout << (K - B - 1) / (A - B) * 2 + 1 << endl;
  }
  return 0;
}