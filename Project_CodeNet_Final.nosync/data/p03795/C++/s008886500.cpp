#include <bits/stdc++.h>
using namespace std;


int main(){
  int n;
  cin >>n;
  int ans=n*800;
  while(n>=15){
    n-=15;
    ans-=200;
  }
  cout << ans << endl;
}
