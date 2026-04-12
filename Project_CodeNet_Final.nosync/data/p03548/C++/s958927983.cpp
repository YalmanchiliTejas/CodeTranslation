#include <bits/stdc++.h>
using namespace std;

int main(){

  int x,y,z,wide=0,ans=0;

  cin>>x>>y>>z;

  for(int i=1; i<100000; i++){

    wide = i * y + (i+1) * z ;

    if(wide > x ) break;

    ans++;
    
  }

  cout<<ans<<endl;

  return 0;

}
