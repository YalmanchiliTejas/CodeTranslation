#include<bits/stdc++.h>
using namespace std;
#define int ll
#define ll long long
signed main(){
  int r,g,b;
  cin>>r>>g>>b;
  cout<<((100*r+10*g+b)%4?"NO":"YES");
}