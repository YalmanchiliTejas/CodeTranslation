#include <bits/stdc++.h>
using namespace std;
int main()
{
 int n,i;
 cin>>n;
 int arr[n];
 for(i=0; i<n; i++)
 cin>>arr[i];
 int count=1;
 int max=arr[0];
 for(i=1; i<n; i++)
{
  if(arr[i]>=max)
  {
    max=arr[i];
    count++;
  }
}
cout<<count;
}