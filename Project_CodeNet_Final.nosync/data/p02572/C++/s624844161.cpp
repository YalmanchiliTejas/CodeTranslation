//Try until you reach your goal
#include <bits/stdc++.h>
using namespace std;
# define ll long long
# define endl "\n"
# define str string
# define vll vector<ll>
# define pb push_back
# define mll map<ll,ll>
# define mp make_pair
# define ff first
# define ss second
# define pll pair<ll,ll>
# define f(x,y) for(int x=0;x<y;x++)
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll x;
    cin>>x;
    ll y=1000000007;
    ll a[x];
    f(i,x){
        cin>>a[i];
    }
    vll v;
    ll s=0;
    f(i,x){
        s+=a[i];
        v.pb(s);
    }
    ll ans=0;
    for(ll i=0;i<x;i++){
        ll k=(v[x-1]-v[i]+y)%y;
        ll k1=a[i]*k;
        k1%=y;
        ans+=k1;
        ans%=y;
    }
    cout<<ans;
    return 0;
}