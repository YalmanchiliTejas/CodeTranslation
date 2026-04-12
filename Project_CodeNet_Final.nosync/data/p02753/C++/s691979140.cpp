#include<bits/stdc++.h>

using namespace std;

int main()
{
  string ar;
  
  cin>>ar;
  
  int A=0,B=0;
  
  for(int i=0 ; i<3 ; i++)
  {
    if(ar[i]=='A')	A++;
    else B++;
  }
  if(A==0 || B==0) cout<<"No\n";
  else	cout<<"Yes\n";
}