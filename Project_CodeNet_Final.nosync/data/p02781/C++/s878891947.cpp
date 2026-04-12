#include<bits/stdc++.h>
using namespace std;
constexpr int64_t mod=1e9+7;

int main()
{
  string s;
  cin>>s;
  int k;
  cin>>k;
  if(k==1)
  {
    cout<<(s.size()-1)*9+(s[0]-'0');
    return 0;
  }
  if(k==2)
  {
    int64_t n=s.size();
    int64_t ans=(n-1)*(n-2)/2*81;
    ans+=((s[0]-'0')-1)*(n-1)*9;
    for (int i = 1; i <s.size() ; ++i)
    {
      if(s[i]!='0') 
      {
        ans+=(n-i-1)*9;
        ans+=s[i]-'0';
        cout<<ans;
        return 0;
      }
    }
    cout<<ans;
    return 0;
  }
  else
  {
    int64_t n=s.size();
    int64_t ans=(n-1)*(n-2)*(n-3)/6*729;
    ans+=(s[0]-'0'-1)*81*(n-1)*(n-2)/2;
    for (int i = 1; i < n; ++i)
    {
      if(s[i]!='0')
      {
        ans+=(n-i-1)*(n-i-2)/2*81;
        ans+=(s[i]-'0'-1)*(n-i-1)*9;
        for (int j = i+1; j < n; ++j)
        {
          if(s[j]!='0')
          {
            ans+=(n-j-1)*9;
            ans+=s[j]-'0';
            cout<<ans;
            return 0;
          }
        }
        cout<<ans;
        return 0;
      }
    }
    cout<<ans;
    return 0;
  }
}