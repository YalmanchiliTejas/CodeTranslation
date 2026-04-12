#include<bits/stdc++.h>
using namespace std;
int main(){
  string r,g,b;
  cin >> r >> g >> b;
  r=r+g+b;
  if(stoi(r)%4==0) cout << "YES" << endl;
  else cout << "NO" << endl;
}
