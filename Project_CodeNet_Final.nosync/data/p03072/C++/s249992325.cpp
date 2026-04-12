
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int ans=1;
  int max=arr[0];
   for(int i=1;i<n;i++)
    {
      
      if(arr[i]>=max)
      {
    ans++;
    max=arr[i];
      }



    }
    cout<<ans;
}
