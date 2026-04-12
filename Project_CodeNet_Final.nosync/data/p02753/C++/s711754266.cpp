#include <bits/stdc++.h>
using namespace std;

int main(){
  string a;
  cin >> a;
  if(a[1] == a[0]&& a[0] == a[2] && a[2] ==a[1]){cout << "No" << endl;}
  else {cout << "Yes" << endl;}
}