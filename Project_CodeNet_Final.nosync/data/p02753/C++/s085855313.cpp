#include<bits/stdc++.h>
using namespace std;
int main()
{
//     int t;
//     cin>>t;
// while(t--){
  string s;
  cin>>s;
  int counta=0;
  int countb=0;
  for(int i=0;i<s.size();i++)
  {
    if(s[i]=='A')
      counta++;
    if(s[i]=='B')
      countb++;
    }
  if(counta==3 or countb==3)
    cout<<"No"<<endl;
  else 
    cout<<"Yes"<<endl;
// }
    
}