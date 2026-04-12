#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;

int main()
{
  string s; int c=0,c1=0;
  cin>>s;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='A')
    {
      c++;
    }
    else
    {
      c1++;
    }
}
  if(c==2||c1==2)
    cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}