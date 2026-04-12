#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1000000007;
#define f(i,a,b) for(i=a;i<b;i++)
#define rf(i,a,b) for(i=a;i>=b;i--)
#define sf(i,s) for(i=0;s[i]!='\0';i++)
#define watch(x) cout << (#x) << " is " << (x) << "\n"
#define inf 1e18
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define tr(v,i) for(typeof(v).begin() i = v.begin(); i != v.end(); i++)
#define pre(v,x) (v.find(x) != v.end())
#define vpre(v,x) (find(all(v),x) != v.end())
#define gcd(x,y) __gcd(x,y)
#define bc(x) __builtin_popcountll(x)
//cin.ignore(1, '\n');
ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    else
    {
        ll t = power(a, b / 2);
        if (b % 2 == 0)
            return t*t;
        else
            return t*t*a;
    }
}
void solve()
{
    ll x;
 cin>>x;
 if(x>=30)
    cout<<"Yes\n";
 else
    cout<<"No\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
