#include<bits/stdc++.h>
using namespace std;
//#define int long long

int a[3*100000];

signed main(){

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int d; cin >> d;
    a[i] = d/10;
  }

  int dmax = a[0];
  for(int i = 0; i < n; i++){
    if(dmax > a[i]) dmax--;
    else dmax = a[i];
    if(dmax <= 0){
      cout << "no" << endl;
      return 0;
    }
  }

  reverse(a,a+n);
  dmax = a[0];
  for(int i = 0; i < n; i++){
    if(dmax > a[i]) dmax--;
    else dmax = a[i];
    if(dmax <= 0){
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;

  return 0;
}

