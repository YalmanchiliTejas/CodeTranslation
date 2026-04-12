#include "bits/stdc++.h"
#include <chrono>
#include <tuple>
#include <string>
#include <random>
#include <cstdio>
#define ll long long int
// #define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,n) for(ll i=0;i<n;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define pll pair<ll, ll>
#define pint pair<int, int>
#define S second
#define F first
#define all(c) (c).begin(),(c).end()
using namespace std; 
ll max(ll a, ll b){ if(a>b)return a;return b;}
ll min(ll a, ll b){ if(a < b) return a;return b;}
const int N = 100001;
vector<pair<ll, ll> > adj[N];

void solve() 
{
    int n;
    cin>>n;

    vector<pair<ll, pair<ll, ll> > > v1, v2;

    rep(i, n)
    {
        int x, y;
        cin>>x>>y;

        v1.pb(mp(x, mp(y, i + 1)));
        v2.pb(mp(y, mp(x, i + 1)));
    }

    sort(all(v1)), sort(all(v2));

    for(int i = 1; i < n; i++)
    {
        adj[v1[i].S.S].pb(mp(v1[i-1].S.S, v1[i].F - v1[i-1].F));
        adj[v1[i-1].S.S].pb(mp(v1[i].S.S, v1[i].F - v1[i-1].F));
    }

    for(int i = 1; i < n; i++)
    {
        adj[v2[i].S.S].pb(mp(v2[i-1].S.S, v2[i].F - v2[i-1].F));
        adj[v2[i-1].S.S].pb(mp(v2[i].S.S, v2[i].F - v2[i-1].F));
    }

    set<pair<ll, ll> > st;

    for(int i = 2; i <= n; i++)
    {
        st.insert(mp(LLONG_MAX, i));
    }

    st.insert(mp(0, 1));

    ll keys[n+1];

    rep(i, n + 1)
    {
        keys[i] = LLONG_MAX;
    }

    keys[1] = 0;

    ll ans = 0;

    // for(auto x:st)
    // {
    //     cout<<x.F<<" "<<x.S<<endl;
    // }
    

    // for(int i = 1; i <= n; i++)
    // {
    //     cout<<i<<endl;
    //     for(auto v:adj[i])
    //     {
    //         cout<<v.F<<" "<<v.S<<endl;
    //     }
    //     cout<<endl;
    // }

    // cout<<st.size()<<endl;

    set<ll> taken;

    while(st.size())
    {
        auto it = st.begin();

        pair<ll, ll> p = *it;
        st.erase(it);
        taken.insert(p.S);

        // cout<<p.F<<" "<<p.S<<endl;

        ans += p.F;

        for(auto v:adj[p.S])
        {
            if(v.S < keys[v.F] && taken.find(v.F) == taken.end())
            {
                st.erase(mp(keys[v.F], v.F));
                st.insert(mp(v.S, v.F));
                keys[v.F] = v.S;
            }
        }

        // cout<<st.size()<<endl;
    }

    cout<<ans<<endl;





}

int main()
{
    #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    // cin>>T;
    int t=0;
    while(t++<T)
    {
        // cout<<"Case #"<<t<<":"<<' ';
        solve();
        // cout<<'\n';
    }

    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}
