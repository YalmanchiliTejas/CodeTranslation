#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)a;i<(int)b;++i)
int main(){
  int x,y,z;cin>>x>>y>>z;
  int cnt=x/(y+z);
  int a=x%(y+z);
  if(a<z)cnt--;
  cout<<cnt<<endl;
    return 0;
}
