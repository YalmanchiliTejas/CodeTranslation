#include<bits/stdc++.h>

using namespace std;
#define ll  long long
#define ld  long double

#define endl '\n'
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const ll mod = 1000000007;
const double PI = 3.141592653589793238463;
const int MAXN=1e5 + 5;
int main()
{
    FAST
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++)
    cin>>arr[i];
   int last=arr[0];
   int ans=1;
   for(int i=1;i<n;i++)
   {
       if(arr[i]>=last)
       {
           ans++;
           last=arr[i];
       }
   }
   cout<<ans<<endl;
    return 0;
}
