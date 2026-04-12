#include<bits/stdc++.h>
using namespace std;
#define light ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define cases() ll t;cin>>t;while(t--)
#define all(c) c.begin(),c.end()
#define PI 3.14159265358979323846
const ll MAX = 1e6+5;
const ll INF = 1e18;
const ll MOD = 1e9+7;

int main()
{
    ll n,x,m,i,j,k,l,p,q,c,d,y;
    cin >> n >> x >> m;
    map<ll,ll> mp,mp2;
    l = x;p = 1;k = 0;j = 0;
    for(i=0;i<n;i++)
    {
        if(mp.find(l)==mp.end())
        {
            mp[l]=p;
            mp2[p]=l;
            k+=l;
            l = (l*l)%m;
            p++;
        }
        else
        {
            j++;
            break;
        }
    }
    if(j==0)
    {
        cout << k;
        return 0;
    }
    q = mp[l];
    j = p-q+1;
    vector<ll> a(j,0);
    for(i=1;i<j;i++)
        a[i] = a[i-1]+mp2[q+(i-1)];
    y = j-1;
    c = (n-p+1)/y;
    d = (n-p+1)%y;
    k+=(c*a[y]);
    k+=(a[d]);
    cout << k;
}