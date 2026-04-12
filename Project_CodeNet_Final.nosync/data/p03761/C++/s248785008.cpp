#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  vector<string>s(n);
  for(int i=0;i<n;i++)
  {
    cin>>s[i];
  }
  vector<vector<int> >a(n);
  for(int i=0;i<n;i++)
  {
    a[i].resize(26);
    for(auto x:s[i])a[i][x-'a']++;
  }
  vector<int>c(26);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<26;j++)
    {
      if(i==0)c[j]=a[i][j];
      else c[j]=min(c[j],a[i][j]);
    }
  }
  int count=0;
  for(int i=0;i<26;i++)count+=c[i];
  //cout<<count<<endl;
  
  string ans;
  if(count==0)
  {
    cout<<ans<<endl;
    return 0;
  }
  int maxlen=0;
  for(int i=0;i<n;i++)
  {
    vector<int>d(26);
    string t;
    for(auto x:s[i])
    {
      if(d[x-'a']<c[x-'a'])
      {
        t.push_back(x);
        d[x-'a']++;
      }
    }
    if(i==0)
    {
      ans=t;
      maxlen=t.length();
    }
    else if(t<ans && maxlen<=t.length())ans=t;
    d.clear();
    t='\0';
  }
  sort(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}
