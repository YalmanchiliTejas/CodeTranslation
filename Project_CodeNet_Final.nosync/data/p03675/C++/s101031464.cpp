#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
#define All(v) v.begin(),v.end()
using namespace std;


int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
      scanf("%d",&a[i]);
  }
  if(n%2 == 0)
  {
     for(int i=n-1;i>=0;i-=2)
     {
         cout<<a[i]<< " ";
     }
     for(int i=0;i<n;i+=2)
     {
         cout<<a[i]<<" ";
     }
  }
  else
  {
      vector < int > v1 , v2;
      int ok = 1;
      for(int i=1;i<n;i++)
      {

          if(ok)
            v1.push_back(a[i]);
          else
            v2.push_back(a[i]);
          ok = !ok;
      }
      for(int i=v2.size()-1;i>=0;i--)
        cout<<v2[i]<< " ";
      cout<<a[0]<< " ";
      for(int i=0;i<v1.size();i++)
        cout<<v1[i]<< " ";
  }
}

