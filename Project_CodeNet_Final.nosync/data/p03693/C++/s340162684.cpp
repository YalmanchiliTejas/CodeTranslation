#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(){
  string r,g,b;
  cin >> r >> g >> b;
  string rgb = r+g+b;
  int RGB = stoi(rgb);
  if (RGB%4==0){
    cout << "YES" <<endl;
  }else{
    cout << "NO" << endl;
  }
  
}
