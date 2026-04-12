
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
int main()
{
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int ans=1000000000;

  //ABセットを1~max(x,y)セットだけ買う全探索を行う．
  //ABをiセット買うとして，Aはx-i,Bはy-iセットとなる．
  //ABを過剰に買う場合，足りない方のみを買いたいので
  for(int i=0;i<=max(x,y);i++)
  {
    int sum=0;
    if(i<=x)  sum+=a*(x-i);
    if(i<=y)  sum+=b*(y-i);
    sum+=2*c*i;

    ans=min(sum,ans);
  }

  cout<<ans<<endl;
}
