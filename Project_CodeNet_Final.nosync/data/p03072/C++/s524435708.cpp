#include<bits/stdc++.h>
using namespace std;
const int N=100010;
typedef long long ll;
int main()
{
  int n,h[150],mx=-1,cnt=0;
  cin>>n;
  for(int i=1;i<=n;i++) cin>>h[i];
  for(int i=1;i<=n;i++)
  {
    if(h[i]>=mx) cnt++;
    mx=max(mx,h[i]);
  }
  cout<<cnt<<endl;
  return 0;
}
