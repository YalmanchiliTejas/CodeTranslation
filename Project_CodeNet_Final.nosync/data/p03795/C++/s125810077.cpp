#include<bits/stdc++.h>
using namespace std;
long long x[1000010],y[1000010];
#define int long long
signed main(){
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  int a;
  cin>>a;

  int b;
  b=a*800;
  a=(a/15)*200;
  cout<<b-a<<'\n';
}
