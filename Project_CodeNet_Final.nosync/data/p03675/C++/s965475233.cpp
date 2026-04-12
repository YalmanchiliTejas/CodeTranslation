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
  int N, M;
  cin >> N;
  M=N/2;
  if (N%2==0) {
    vector<int64_t> A(M);
    vector<int64_t> B(M);
    for (int i=0; i<M; i++) {
      cin >> A[i] >> B[i];
    }
    if (M==1) {
      cout << B[0] << " " << A[0] << endl;
    }
    else {
      for (int i=M-1; i>=0; i--) {
        cout << B[i] << " ";
      }
      for (int i=0; i<M-1; i++) {
        cout << A[i] << " ";
      }
      cout << A[M-1] << endl;
    }
  }
  else {
    if (M==0) {
      int a;
      cin >> a;
      cout << a << endl;
    }
    else {
      vector<int64_t> A(M+1);
      vector<int64_t> B(M);
      for (int i=0; i<M; i++) {
        cin >> A[i] >> B[i];
      }
      cin >> A[M];
      if (M==1) {
        cout << A[1] << " " << A[0] << " " << B[0] << endl;
      }
      else {
        for (int i=M; i>=0; i--) {
          cout << A[i] << " ";
        }
        for (int i=0; i<M-1; i++) {
          cout << B[i] << " ";
        }
        cout << B[M-1] << endl;
      }
    }
  }
}