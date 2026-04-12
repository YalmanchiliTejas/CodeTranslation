#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

using namespace std;

int main() {
  int n,h[30];
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> h[i];
  
  int sum = 1;
  bool flag;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j <= i-1; j++) {
      if(h[i] >= h[j]) flag = 1;
      else  {
        flag = 0; 
        break;
      }
    }
    if(flag) sum++;
  }
  cout << sum << endl; 
}