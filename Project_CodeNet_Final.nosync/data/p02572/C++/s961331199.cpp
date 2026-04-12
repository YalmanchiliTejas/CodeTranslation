#include <bits/stdc++.h>

using namespace std;

int main()
{
    
     long long int n;
    cin>>n;
    long long int p=1000000007,ans=0;
     long long int arr[n];
    for(int i=0;i<n;i++)
    {
         cin>>arr[i];
    }
    long long int x=0;
    for(int i=0;i<n;i++)
    {
        ans =(ans + (arr[i] * x)) %p;
         x =(x+arr[i])%p;
         
    }
 
   
   cout<<ans<<endl;
    
	
	return 0;
}
