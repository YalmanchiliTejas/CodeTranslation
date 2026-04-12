#include<bits/stdc++.h>
using namespace std;
#define bitCount(num)  __builtin_popcount(num)
#define pb push_back
#define ll long long
#define bye return 0;
#define f(i,a,b) for( long long i=a;i<b;i++)
#define testCases long long t;cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define newLine <<"\n"
#define all(x) (x).begin(), (x).end()
#define vll vector<long long>

int main()
{
    fast
   
    	ll n;
    	cin>>n;
    	vector<ll> a(n,0);
    	f(i,0,n)cin>>a[i];
    	ll ans=0;

    	vector<ll> pSum(n,0);
    	pSum[n-1]=a[n-1];
    	
    	for(ll j=n-2;j>=0;j--)
    	{
         pSum[j]=pSum[j+1]+a[j];
         pSum[j]%=1000000007;
    	}

    	for(ll j=1;j<n;j++)
    	{
    	  ll tempAns= a[j-1]*pSum[j];
    	  ans+=tempAns;
    	  ans%=1000000007;
    	}

    	cout<<ans<<endl;


    
    bye
}