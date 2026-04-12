#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<int> ans(26,1e9);
  for(int i=0;i<n;i++)
  {
    string s;
    cin>>s;
    vector<int> v(26,0);
    for(auto i:s)
      v[i-'a']++;
    for(int i=0;i<26;i++)
      ans[i]=min(ans[i],v[i]);
  }
  for(int i=0;i<26;i++)
  {
    while(ans[i]--)
      cout<<char('a'+i);
  }
    
  return 0;
}