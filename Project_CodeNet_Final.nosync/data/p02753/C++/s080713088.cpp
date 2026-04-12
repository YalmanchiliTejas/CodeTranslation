#include<bits/stdc++.h> 
using namespace std; 
#define ll long long
#define FASTIO ios_base::sync_with_stdio(0); cin.tie(NULL);
int main() 
{ 
  FASTIO;
  string s;
  cin>>s;
  sort(s.begin(),s.end());
  if(s[0]==s[2]) cout<<"No"<<"\n";
  else cout<<"Yes"<<"\n";
  
    return 0; 
} 