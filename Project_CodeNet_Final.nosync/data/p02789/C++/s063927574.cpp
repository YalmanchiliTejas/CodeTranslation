
// Problem : A - AC or WA
// Contest : AtCoder Beginner Contest 152
// URL : https://atcoder.jp/contests/abc152/tasks/abc152_a
// Memory Limit : 1024,000000 MB 
// Time Limit : 2000,000000 milisec 
// Powered by CP Editor (https://github.com/coder3101/cp-editor)

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include <cmath>
#include <cstdio>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <map>
#include <set>
#include <vector>

using namespace std;

void preambule() {
  cin.tie(0);
  cout.precision(16);
  cout << fixed;
}

int n;
int m;

void input() {
  cin >> n >> m;
}

void solve1() {
  if (n == m) {
    cout << "Yes";
    
    exit(0);
  }
  
  cout << "No";
}

int main() {
#ifdef _DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  preambule();
  input();
  solve1();
}
