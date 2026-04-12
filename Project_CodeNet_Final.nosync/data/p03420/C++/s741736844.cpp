#include<bits/stdc++.h>
using namespace std;
constexpr int64_t mod=1e9+7;

int main()
{
  int64_t n,k;
  cin>>n>>k;
  int64_t cnt=0;

  for (int i = k; i < n; ++i)
  {
    if(i==0) {
      for (int b = 1; b <= n; ++b)
      {
        cnt+=n/b;
      }
      continue;
    }
    vector<int64_t> vec(1,n);
    int64_t tmp=n/i;
    for (int j = 1; j <= tmp; ++j)
    {
      int64_t a=(n-i)/j;
      if(i+1<=a) vec.emplace_back(a);
      else break;
    }
    vec.emplace_back(i+1);
    for (int i = 1; i < vec.size(); ++i)
    {
      if(i!=vec.size()-1) cnt+=(vec[i-1]-vec[i])*i;
      else cnt+=(vec[i-1]-vec[i]+1)*i;
    }
  }
  cout<<cnt;
}