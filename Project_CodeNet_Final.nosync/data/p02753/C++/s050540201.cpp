#include<bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin>>s;
  unordered_map<char,int> m;
  for(int i=0;i<s.size();i++)
    m[s[i]]=1;
  
  if(m.size()==2)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;
}