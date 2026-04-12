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
void Yes(){
  cout << "Yes" << endl;
}
void YES(){
  cout << "YES" << endl;
}
void No(){
  cout << "No" << endl;
}
void NO(){
  cout << "NO" << endl;
}
int main(){
  int N;
  cin >> N;
  
  cout << N*800 - (N/15) * 200 << endl;
}