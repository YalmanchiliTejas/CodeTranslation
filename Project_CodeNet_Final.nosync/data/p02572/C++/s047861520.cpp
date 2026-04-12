#include <bits/stdc++.h>
//#include<stdio.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long int
#define f(i, a, b) for(int i=a; i<b; i++)
#define fr(i, a, b) for(int i=a; i>=b; i--)
#define l long int
#define endl '\n'
#define pb push_back
#define pf pop.front()

using namespace std;
ll MOD=1e9+7;
int main()
{
FAST
l n , i,j;
cin>>n;
ll a[n],ans=0,sum=0,s=0;

for(i=0;i<n;i++)
{
cin>>a[i];
sum+=a[i];
}
//s=a[0];
for(i=0;i<n-1;i++)
{
	s=a[i];
	sum-=s;
	ans=(ans+(a[i]%MOD)*(sum%MOD)%MOD)%MOD;

}
cout<<ans;
}






