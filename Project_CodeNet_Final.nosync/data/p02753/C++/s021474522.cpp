#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main()
{
  int I, J, K, L, M, N, S;
  double i, j, k;
  char ch[3];
  bool check;
  cin >> ch;
  if(ch[0]==ch[1] && ch[1]==ch[2]){
    check = false;
  }else{
    check = true;
  }

  if (check)
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }
}