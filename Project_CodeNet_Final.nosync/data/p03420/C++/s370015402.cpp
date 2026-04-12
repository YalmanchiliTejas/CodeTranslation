#include <iostream>
#define MAX 100010

using namespace std;
typedef long long ll;

ll n,k,ans,na,r;

int main()
{
    cin>>n>>k;
    for(ll b=k+1;b<=n;b++){
      r=(n-(b-1))%b;
      na=(n-(b-1))/b+1;
      ans+=(b-1-k+1)*na;
      if(n%b>=k&&r)ans+=n%b-k+1;
      if(k==0)ans--;
      //cout<<ans<<'\n';
    }
    cout<<ans;
    return 0;
}
