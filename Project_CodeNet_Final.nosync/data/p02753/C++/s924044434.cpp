#include<bits/stdc++.h>
using namespace std;
int main()
{
  string S,C="No";
  cin>>S;
  if(S.at(0)!=S.at(1))C="Yes";
  if(S.at(0)!=S.at(2))C="Yes";
  if(S.at(1)!=S.at(2))C="Yes";
  cout<<C<<endl;
}