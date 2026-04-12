#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
  int n;
  cin>>n;
  vector<string> s(n);
  for(int i=0;i<n;i++)
    cin>>s[i];
  vector<int> cou(26,1000000000);
  for(int i=0;i<26;i++)
  {
    for(int j=0;j<n;j++)
    {
      int tmp=0;
      for(int k=0;k<s[j].size();k++)
        if(s[j][k]==char('a'+i))
          tmp++;
      cou[i]=min(cou[i],tmp);
    }
  }
  for(int i=0;i<26;i++)
  {
    for(int j=0;j<cou[i];j++)
      cout<<char('a'+i);
  }
  cout<<endl;
}
