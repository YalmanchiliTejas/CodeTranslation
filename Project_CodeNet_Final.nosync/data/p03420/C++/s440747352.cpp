#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define ff first
#define ss second
#define MAXN  1000005
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    ll ans=0,e,r,c,d;
    cin>>n>>k;
    if(k==0){
        ans=n*n;
        cout<<ans;
        return 0;
    }
    for(ll i=k+1;i<n+1;i++){
        e=n/i;
        r=n%i;
        c=(i-k)*e;
        d=max(0LL,r-k+1);
        ans+=(c+d);
    }
    cout<<ans;


    return 0;
}

