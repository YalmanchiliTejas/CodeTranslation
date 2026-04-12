#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,sum=0;
  cin >> n;
  sum+=800*n;
  sum-=(n/15)*200;

  cout << sum << endl;
  return 0;
}
