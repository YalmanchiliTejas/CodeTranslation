#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int ans = INT_MAX;

  for(int k=0; k<=max(x,y)*2; k++){
    int price =c*k + max(x-k/2,0)*a + max(y-k/2,0)*b;

    if(ans>= price){
      ans= price;
    }
  }
  cout<< ans <<endl;
  return 0;
}
