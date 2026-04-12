#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int max(int a,int b){
  if(a>b) return a;
  else return b;
}
double min(double a,double b){
  if(a<b) return a;
  else return b;
}
int absolute(int a,int b){
  if(a-b<0) return -(a-b);
  else return a-b;
}
int sum_keta(int n){
  if(n==0) return 0;
  return n%10 + sum_keta(n/10);
}
int main(void){
  int X,Y,Z; cin >> X >> Y >> Z;
  int ans;
  
  ans = X/(Y+Z);
  if(X-ans*(Y+Z) < Z) ans--;
  cout << ans << endl;
}