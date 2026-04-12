#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  
  int arr[2]={0};
  
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='A')
      arr[0]++;
    else if(s[i]=='B')
      arr[1]++;
  }
  
  if(arr[0]>=1 && arr[1]>=1)
    cout<<"Yes";
  else
    cout<<"No";
  
  return 0;
}
