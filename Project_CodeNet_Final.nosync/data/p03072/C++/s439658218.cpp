#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long int ll;
typedef vector<pair<ll,ll> > Q;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

int main()
{
  int n,ans=1;
  cin>>n;
  int h[n];
  rep(i,n) cin>>h[i];

  for(int i=1;i<n;i++)
  {
    bool flag=true;
    for(int j=0;j<i;j++)
    {
      if(h[i]<h[j]) flag=false;
    }
    if(flag) ans++;
  }

  cout<<ans<<endl;
}