#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define start_routine() int begtime = clock();
#define end_routine() int endtime = clock(); \
                      cerr << "\n\n" << "Time elapsed: " << \
                      (endtime - begtime)*1000/CLOCKS_PER_SEC << " ms\n\n"; \
                      return 0
#define ll long long int
#define ull unsigned long long int
#define db long double
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound 
#define pii pair<int , int>
#define pdd pair<db , db>
#define pll pair<ll , ll>
#define vpl vector<pll >
#define vll vector<ll >
#define mod 1000000007
#define mod1 998244353 
#define inf 1000000000000000007
#define eps 0.000001
#define stp fixed<<setprecision(20)
#define endl '\n'


int main()
{
    fastio;
    #ifdef APNA_IO
        start_routine();
        freopen("input.txt", "rt", stdin);
        freopen("output.txt", "wt", stdout);    
    #endif

    ll n;cin>>n;
    ll a[n+1];
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    multiset<ll> m;

    for(ll i=n;i>0;i--)
    {
        auto p=(m.ub(a[i]));
        if(p==m.end())
        {
            m.insert(a[i]);
            continue;
        }

        ll x=*p;
        m.erase(m.find(x));
        m.insert(a[i]);
    }
    cout<<m.size();

    #ifdef APNA_IO
        end_routine();
    #endif
}
