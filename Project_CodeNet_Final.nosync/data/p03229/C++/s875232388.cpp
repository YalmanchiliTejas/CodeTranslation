#include<bits/stdc++.h>
using namespace std;
constexpr int64_t mod=1e9+7;

int main()
{
  int64_t n;
  cin>>n;
  std::vector<int64_t> a(n);
  for(auto&& e: a) {
    cin>>e;
  }
  sort(a.begin(), a.end());
  std::multiset<int64_t> one,zero;
  one.insert(a[0]);
  one.insert(a.back());
  for (int i = 1; i < n-1; ++i)
  {
    zero.insert(a[i]);
  }
  int64_t ans=a.back()-a[0];
  while(!zero.empty()){
    int64_t one_min=*one.begin(),one_max=*one.rbegin();
    int64_t zero_min=*zero.begin(),zero_max=*zero.rbegin();
    int64_t tmp1=abs(one_min-zero_max),tmp2=abs(one_max-zero_min);
    if(tmp1>tmp2){
      one.erase(one.lower_bound(one_min));
      one.insert(zero_max);
      zero.erase(zero.lower_bound(zero_max));
    }
    else{
      one.erase(one.lower_bound(one_max));
      one.insert(zero_min);
      zero.erase(zero.lower_bound(zero_min));
    }
    ans+=max(abs(one_min-zero_max),abs(one_max-zero_min));
  }
  cout<<ans;
}