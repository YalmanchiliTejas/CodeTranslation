#include <cstdlib>
#include <iostream>
#include <typeinfo>
//#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
  int x;
  cin >> x;
  vector<int> a{3, 5, 7};
  bool b = false;
  for (int i : a)
  {
    if(i==x){
      b = true;
      break;
    }
  }
  if(b){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
  return 0;
}