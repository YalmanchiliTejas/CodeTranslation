#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(int)(n);i++)
using namespace std;
using ll=long long;

int main()
{
  int N;
  cin>>N;
  ll A, ans=0, sumA=0;
  while(N-->0){
    cin>>A;
    ans=(ans + A*sumA)%(ll)(1e9+7);
    sumA=(sumA+A)%(ll)(1e9+7);
  }
  cout<<ans<<endl;
  return 0;
}