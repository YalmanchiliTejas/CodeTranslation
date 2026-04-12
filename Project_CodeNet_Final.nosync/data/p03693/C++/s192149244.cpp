#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int a,b,c;
  cin>>a>>b>>c;
  int r=a*100+b*10+c;
  cout<<(r%4?"NO":"YES")<<endl;
  return 0;
}
