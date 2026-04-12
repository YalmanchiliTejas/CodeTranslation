#include<bits/stdc++.h>
using namespace std;
constexpr int64_t mod=1e9+7;

int main()
{
  int r,g,b;
  cin>>r>>g>>b;
  if((2*g+b)%4==0)
  {
    cout<<"YES"<<endl;
  }
  else cout<<"NO"<<endl;
}