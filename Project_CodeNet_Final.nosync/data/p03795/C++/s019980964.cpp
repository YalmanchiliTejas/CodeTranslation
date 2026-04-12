#include <bits/stdc++.h>
using namespace std;

int main() {
  int G,L=0;
  cin >> G;
  L = G / 15;
  G *= 800;
  L *= 200;
  cout << G - L <<endl;
}