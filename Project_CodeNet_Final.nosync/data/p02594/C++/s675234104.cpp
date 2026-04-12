    #include<bits/stdc++.h>
    using namespace std;
    #define inp(k)           ll k;cin>>k;
    #define in2(n,k)       ll n, k; cin>>n;cin>>k;
    #define in3(n,k,r)       ll n, k,r; cin>>n;cin>>k;cin>>r;
    #define ll long long
    #define dl double
    #define ch char
    #define f(i,a,b) for(ll i=a;i<b;i++)
    #define rf(i,a,b) for(ll i=a-1;i>=b;i--)
    #define Godspeed                ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define vpl vector< pair<ll,ll> >
    #define vpi vector< pair<int,int> >
    #define vi vector<int>
    #define vl vector<ll>
    #define vdl vector<dl>
    #define vch vector<char>
    #define pll pair<ll,ll>
    #define pb push_back
    #define mp make_pair
    #define fr first
    #define se second
    #define PI 3.14159265
    /*vl v[10005];
    ll cnt=0;
    ll a[51][51]={0};
    bool visited[10005]={0};
    void dfs(ll u)
    {
        visited[u]=1;
        f(i,0,v[u].size())
        {
            ll f=v[u][i];
            if(!visited[f])
            {
                dfs(f);
            }
        }
    }*/
    void solve()
    {
        inp(n);
        if(n>=30)cout<<"Yes";
        else cout<<"No";
    }
    int32_t main(void)
    {
        Godspeed;
        int q;
        q=1;
        //cin>>q;
        while (q--)
        {
            //cout<<"           ";
            solve();cout<<endl;
        }
        return 0;
    }
