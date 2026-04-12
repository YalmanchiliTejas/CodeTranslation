#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define fi first
#define se second
#define mod 1000000007
#define repf(i,a,b) for(ll i=a;i<b;i++)
#define repb(i,a,b) for(ll i=a;i>=b;i--)
#define mp make_pair
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

using namespace std;

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    repf(i,0,n) cin>>a[i];
    multiset<ll> s;
    ll ans=0;
    s.insert(a[0]);
    ans++;
    repf(i,1,n)
    {
        multiset<ll>::iterator it=s.lower_bound(a[i]);
        if(it==s.begin()) ans++;
        else{
            --it;
            s.erase(it);
        }
        s.insert(a[i]);
    }
    cout<<ans<<endl;
    return 0;
}