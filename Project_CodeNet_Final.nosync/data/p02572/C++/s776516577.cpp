#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(false);   cin.tie(NULL); cout.tie(NULL);

#define endl "\n";


#define mod 1000000007
#define loop(i,s,n)  for(ll i=s;i<n;i++)
#define test  ll t; cin>>t; while(t--)
#define p push_back
typedef long long ll;
int main()
{IOS
ll  n,i,j,k,sum=0,f=0,count=0;

cin>>n;
ll a[n]={0};
for(i=0;i<n;i++)
{
    cin>>a[i];
}

for(i=0;i<n;i++)

{
    sum=(sum+a[i]);

}

for(i=0;i+1<n;i++)
{
    sum=sum-a[i];
    k=sum%mod;

    count=(count+(a[i]*k)%mod);

}
cout<<count%mod;




return 0;
}
