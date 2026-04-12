#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <utility>
#include <set>
#include <vector>
#include <functional>
#include <map>
#include <queue>
using namespace std;
int main()
{
  long long N,K;
  cin>>N>>K;
  long long ans=0;
  if (K)
  {
    for (long long b=K+1;b<=N;b++)
    {
      long long s=(N+1)/b,h=(N+1)%b;
      if (h>K) ans+=s*(b-K)+h-K;
      else ans+=s*(b-K);
    }
  }
  else ans=N*N;
  cout<<ans<<endl;
  //system("pause");
  return 0;
}