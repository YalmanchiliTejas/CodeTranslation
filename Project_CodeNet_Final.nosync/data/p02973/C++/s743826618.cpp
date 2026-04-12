#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define lf long double
typedef vector <ll> vi;
typedef pair <ll,ll> ii;
typedef vector <pair <int,int> >vii;
typedef vector <vector <ll> > vv;
typedef vector <string> vs;
ll mod=1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n;
    cin>>n;
    vi a(n);
    for(ll i=0;i<n;i++)
        cin>>a[i];
    multiset<ll> ma;
    for(ll i=0;i<n;i++)
    {
        if(ma.empty() || a[i]<=(*ma.begin()))
        {
            ma.insert(a[i]);
        }
        else
        {
            auto i1=ma.lower_bound(a[i]);
            auto j1=prev(i1);
            ma.erase(j1);
            ma.insert(a[i]);
        }
    }
    cout<<ma.size()<<endl;
}
