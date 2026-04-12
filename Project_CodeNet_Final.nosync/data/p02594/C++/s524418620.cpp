#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define fo(i,n) for(ll i=0;i<n;i++)
#define fo1(i,n) for(ll i=1;i<=n;i++)
#define loop(i,a,b)for(ll i=a;i<=b;i++)
#define loopr(i,a,b)for(ll i=b;i>=a;i--)
#define vll vector<ll> 
#define vvl vector<vll>
#define pii pair<ll,ll>
#define F first
#define S second
#define endl "\n"
#define M 1000000007
ll max(ll a,ll b){if (a>b) return a; else return b;}

ll po(ll x, ll y){
    if(y==0)
    return 1;
    if(y%2){
        return ((x)*(po(x,y/2)%M)*(po(x,y/2)%M))%M;
    }
   return ((po(x,y/2)%M)*(po(x,y/2)%M))%M;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll t=1;
    //cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n>=30)
        cout<<"Yes"<<endl;
        else
        cout<<"No"<<endl;
    }
return 0;
}