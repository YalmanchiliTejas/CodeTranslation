#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main()
{
  int flag=0;
  string S;
  cin>>S;

  for(int i=0;i<2;i++)
  {
   
    if(S[i]!=S[i+1])
    {
      if( S[i]!='C'&& S[i+1]!='C')
       {
         flag++;
         goto label;
       }
    }
  }

label:
  if(flag==0)
   cout<<"No";
   else
   cout<<"Yes";
  return 0;
}