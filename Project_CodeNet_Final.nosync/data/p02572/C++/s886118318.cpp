#include <bits/stdc++.h>
#include <set>
#define ll long long 
#include <string>
#define pb push_back
#define mp make_pair
# define pi 3.14159265358979323846
#define mod 1000000007
using namespace std;
int main()
{ 
	 #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
    #endif
    ll int n;
    cin>>n;
    ll int a[n],i,s=0;
    for(i=0;i<n;i++)
    {
    	cin>>a[i];
    	s+=a[i];
    }
    ll int ss[n+1];
    ss[0]=s;
    for(i=1;i<=n;i++)
    {
    	s-=a[i-1];
    	ss[i]=s;
    }
    ll int ans=0;
    for(i=1;i<=n;i++)
    {
    	ans=ans%mod+((a[i-1]%mod)*((ss[i])%mod)%mod);

    }
    ans=ans%mod;
    cout<<ans<<endl;


    





    	

}

	
		
	
	
	
	



