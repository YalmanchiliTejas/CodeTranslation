#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long int ll;
int main()
{
   int n;
   cin>>n;
   ll arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];
   ll tot=0,prev=arr[0];
   for(int i=1;i<n;i++)
   {
       tot = ((tot)%M+ (prev*arr[i])%M)%M;
       prev = (prev+arr[i])%M;
   }
   cout<<tot%M<<endl;
}
