#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z,ans=1;
  cin>>x>>y>>z;
  while(1){
    if(ans*y+(ans+1)*z > x){
      cout<<(ans-1);
      return 0;
    }
    ans++;
  }
}
