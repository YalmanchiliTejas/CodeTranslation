#include<iostream>
#include<string>
using namespace std;
int main()
{
  int n,k,i;
  cin>>n;
  char ar[n];
  cin>>ar;
  cin>>k;
  
  char ch=ar[k-1];
  for(i=0; i<n; i++)
  {
    if(ar[i]!=ch)
      cout<<"*";
    else
      cout<<ar[i];
  }
}
