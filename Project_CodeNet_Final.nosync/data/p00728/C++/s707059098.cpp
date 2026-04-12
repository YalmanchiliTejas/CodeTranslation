#include <bits/stdc++.h>
using namespace std;
int main(){
  int n, x, mx ,mn;
  int a[100] = {};
  double Sum,Sum2,Sum3;
  int Sum4;
  while(1){
    cin >> n;
    if(n == 0) break;
    for(int i=0;i<n;i++)cin >> a[i];
    mx = a[0];
    mn = a[0];
    for(int i=0;i<n;i++){
      mx = max(mx,a[i]);
      mn = min(mn,a[i]);}
    Sum = 0;
    for(int i=0;i<n;i++) Sum += a[i];
    Sum2 = Sum - mx - mn;
    Sum3 = Sum2 / (n-2);
    Sum4 = Sum3;
    cout <<  Sum4 << endl;
    for(int i =0; i<n;i++)a[i] = 0;
    

  }

  return 0;
}
