#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
int main() 
{
	 ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     
		 int n;
		 cin>>n;
		 int a[n];
		 for(int i=0;i<n;i++)
		 cin>>a[i];
		 vector<int>v;
		 if(n%2==0)
		{ for(int i=n-1;i>0;i-=2)
		 {
			 v.pb(a[i]);
			
		 }
		 for(int i=0;i<n;i+=2)
		 v.pb(a[i]);}
		 else
		 {
			 for(int i=n-1;i>=0;i-=2)
		 {
			 v.pb(a[i]);
			
		 }
		 for(int i=1;i<n;i+=2)
		 v.pb(a[i]);}
		 
		 
		
		 for(auto x: v)
		 {
			 cout<<x<<" ";
		 }
		 
	
}
