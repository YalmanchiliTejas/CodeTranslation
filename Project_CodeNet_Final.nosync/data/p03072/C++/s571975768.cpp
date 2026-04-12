/*input
5
1 7 2 11 15
*/

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define endl "\n"
#define sp " " 
#define all(v) v.begin(),v.end()
#define makepr(a,b) make_pair(a, b)
#define loop(i,k,n) for(ll i=k;i<n;i++)
#define rlop(i,n,k) for(ll i=n-1;i>=k;i--)
#define lop(i ,a) for(auto i : a)
#define vecl vector<ll>
#define vecprl vector<pair<ll, ll> > v;
#define mpll map<ll, ll>
#define mpsl map<string, ll>
#define setl set<ll>
#define mod(a,b) a%b
#define PI 3.14159265

typedef long long ll;
typedef long double ld;

int main()
{
    fast;
    ll n;
    cin >>n;
    ll a[n];
    loop(i, 0,n)
    {
        cin >>a[i];
       
    }
    ll mx = a[0], ans =1;

    loop(i ,1, n)
    {
        if(a[i]>=mx)
        {
            ans++;
            mx= max(mx, a[i]);
        }
       
    }
    cout<<ans<<endl;
    return 0;
}