#include<bits/stdc++.h>
using namespace std;
int main()
{
  int r, g, b, s;
  cin >> r >> g >> b;
  s = g * 10 + b;
  if(s % 4 == 0){
  	cout<< "YES" << endl;
  }else{
  	cout << "NO" << endl;
  }
}