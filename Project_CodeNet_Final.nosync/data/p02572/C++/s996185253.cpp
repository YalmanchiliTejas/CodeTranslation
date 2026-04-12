/**Bismillahir Rahmanir Rahim.**/
#include<bits/stdc++.h>
#define ll 	 long long
#define pb push_back
#define mp make_pair
using namespace std;

int main() 
{ 

ll n; cin>>n;

vector<ll>a(200009), sum(200009, 0);

for(ll i=0; i<n; i++) {
	cin>>a[i];
	sum[i]=a[i];
}

sum[n]=0;

for(ll i=n-1; i>=0; i--)
{
	sum[i]+=sum[i+1];
}

ll ans=0;

for(ll i=0; i<n; i++)
{
	ans= (ans+ (a[i]*(sum[i+1]%1000000007)))%1000000007;
}

cout<<ans<<endl;
    return 0;
} 