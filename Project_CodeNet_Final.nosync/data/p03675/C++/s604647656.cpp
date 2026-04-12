#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long  int n,a,i,sum=0,l;
    vector<int>v;
    cin>>n;
    for(i=0;i<n;i++)
    {cin>>a;
    v.push_back(a);

    }

      for(int i=n-1;i>=0;i-=2)
      {
          cout<<v[i]<<" ";
      }
      if(n%2==0){l=0;}
      else{l=1;}
      for(int i=l;i<n;i+=2)
      {
          cout<<v[i]<<" ";
      }


}
