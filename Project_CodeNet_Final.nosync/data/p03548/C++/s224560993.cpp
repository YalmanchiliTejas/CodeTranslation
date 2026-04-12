#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main(){
  int x,y,z,ans=0;
  cin>>x>>y>>z;
  while ((ans*y+(ans+1)*z)<=x) {
    if (((ans+1)*(y+z)+z)<=x) {
      ans+=1;
    }
    else{
      break;
    }
  }
  cout<<ans<<endl;
}

