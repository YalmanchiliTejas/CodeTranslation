#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
#define pi 3.14159265358979323846264338327950L
using namespace std;

int main() {
  int N, K;
  string S;
  cin >> N >> S >> K;
  for (int i=0; i<N; i++) {
    if (S[i]!=S[K-1]) {
      S[i]='*';
    }
  }
  cout << S << endl;
}
