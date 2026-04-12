#include<iostream>
#include<cmath>
#include<algorithm>
#include <iomanip> 
#include<vector>
#include<queue>
#include<set>
#define fo(i,n) for(ll i=0;i<n;i++)
#define f(i,n) for(ll i=1;i<n;i++)
#define ff(i,k,n) for(ll i=k;i<n;i++)
#define ll long long
#define  vt  vector<ll>
#define pb(x)  push_back(x)
#define   vts  vector<string>
/*Elegizip, elegizip otken sol bir shaktar-ai
 Elendeter zamanymnyn otip bara zhatkanny-ai
Umytylmas-Umytylmas Kairan esil shaktar-ai
Zamanymnyn kolyn bulgap otip bara jatkany-ai
 kairan esil , kairan esil shaktar-ai
kolyn bulgap zamanymnyn otip bara jatkany-ai;*/
using namespace std;



int main()
{ios::sync_with_stdio(0);
ll x;
ll mo=1e9+7;
cin>>x;
ll a[x];
ll sum=0;
fo(i,x){
    cin>>a[i];
    sum+=a[i];
}
ll ans=0;
fo(i,x){
    ans+=((sum-a[i])%mo)*a[i];
    sum-=a[i];
    ans%=mo;
}
cout<<ans%mo;
}



