#include<bits/stdc++.h>
using namespace std;
bool check_row(int r,vector<string> &v)
{
  for(auto i:v[r])
    if(i=='#')
      return false;

  return true;
}
bool check_column(int c,vector<string> &v)
{
  for(auto i:v)
    if(i[c]=='#')
      return false;
  return true;
}
bool found(vector<string> &v)
{
  for(int i=0;i<v.size();i++)
    if(check_row(i,v))
      return true;

  for(int i=0;i<v[0].size();i++)
    if(check_column(i,v))
       return true;

  return false;
}
string util(vector<string> &v)
{
  for(int i=0;i<v.size();i++)
    if(check_row(i,v))
      return "r"+to_string(i);

  for(int i=0;i<v[0].size();i++)
    if(check_column(i,v))
       return "c"+to_string(i);
}
void delete_rc(vector<string> &v)
{
  string td=util(v);
  if(td[0]=='r')
  {
    int r=stoi(td.substr(1,td.length()-1));
    v.erase(v.begin()+r);
  }
  else
  {
    int c=stoi(td.substr(1,td.length()-1));
    for(int i=0;i<v.size();i++)
    {
      string h=v[i];
      string l="";
      for(int j=0;j<h.length();j++)
        if(j!=c)
          l+=h[j];
      v[i]=l;
    }
      
  }
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<string> v(n);
  for(auto &i:v) cin>>i;
  while(found(v))
  {
    delete_rc(v);
  }
  for(auto i:v){
    for(auto j:i)
      if(j=='3')
        continue;
      else
        cout<<j;
    cout<<"\n";
  }
  return 0;
}
