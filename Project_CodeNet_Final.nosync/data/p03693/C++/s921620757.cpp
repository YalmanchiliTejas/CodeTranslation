#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){

  int a,b,c,sum;
  cin >> a >> b >> c;

  sum = a*100 + b * 10 + c;

  if(sum % 4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }


}