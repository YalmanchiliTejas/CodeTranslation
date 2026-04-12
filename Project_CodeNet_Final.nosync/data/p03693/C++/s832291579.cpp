#include <bits/stdc++.h>
using namespace std;

int max(int a,int b){
  if(a>b) return a;
  else return b;
}
int absolute(int a,int b){
  if(a-b<0) return -(a-b);
  else return a-b;
}
int main(){
  int r,g,b;
  cin >> r >> g >> b;
  
  if( (r*100+g*10+b) % 4 == 0) cout << "YES" << endl;
  else cout << "NO" << endl;
}