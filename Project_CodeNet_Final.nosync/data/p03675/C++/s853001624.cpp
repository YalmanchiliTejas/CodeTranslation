#include <bits/stdc++.h>
using namespace std;
 
#define ll long int
 

int main() {
	// your code goes here
ll n,i,j;
cin>>n;
ll ar[n+1];
for(i=1;i<=n;i++)
 {
   cin>>ar[i]; 
 }
for(i=n;i>=1;i-=2)
 {
   cout<<ar[i]<<" "; 
 }
if(n%2==0)
{
for(i=1;i<=n;i+=2)
 {
   cout<<ar[i]<<" "; 
 }
}
else
 {
  for(i=2;i<=n;i+=2)
  {
   cout<<ar[i]<<" "; 
  }  
 }
	return 0;
}