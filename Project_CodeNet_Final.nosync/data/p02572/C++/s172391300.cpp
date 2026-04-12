/*
  Krishnakant Tiwari
  Problem Link:

 */
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
using namespace std;
typedef long long ll;
#define _cin      ios_base::sync_with_stdio(0);  cin.tie(0);
#define endl "\n"
#define pb push_back
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define repd(i,a,b) for(ll i=a;i>=b;--i)
#define mp make_pair
#define hell 1000000007
#define vvll vector<vector<ll> >
#define vll vector<ll>
#define mll map<ll,ll>
#define sz(x) (ll)x.size()
#define sll set<ll>
#define pll pair<ll,ll>
#define F first
#define S second
#define eb	emplace_back
#define ppb	pop_back
#define pf	push_front
#define ppf	pop_front
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define precise(x)	cout<<fixed<<setprecision(x)
const ll MAX = 1000004;
const ll INF = 1e18L + 5;
template <class T, class U>
void chmin(T &t, const U &u)
{
    if (t > u) t = u;
}
template <class T, class U>
void chmax(T &t, const U &u)
{
    if (t < u) t = u;
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T)
{
    cerr << " " << H;
    debug_out(T...);
}
template <typename Arg1>
void pn(Arg1 &&arg1)
{
    cout << arg1 << "\n";
}
template <typename Arg1, typename... Args>
void pn(Arg1 &&arg1, Args &&... args)
{
    cout << arg1 << "\n";
    pn(args...);
}
template <typename Arg1>
void ps(Arg1 &&arg1)
{
    cout << arg1 << " ";
}
template <typename Arg1, typename... Args>
void ps(Arg1 &&arg1, Args &&... args)
{
    cout << arg1 << " ";
    ps(args...);
}
template <typename Arg1>
void read(Arg1 &&arg1)
{
    cin >> arg1;
}
template <typename Arg1, typename... Args>
void read(Arg1 &&arg1, Args &&... args)
{
    cin >> arg1;
    read(args...);
}

ll g[MAX];
ll a[MAX];

void solve()
{

    ll sum = 0;
    ll n;
    read(n);
    ll a[n];
    ll pre[n];
    rep(i, 0, n)
    {
        read(a[i]);
        sum+=a[i];
        if(i){
        	pre[i]=a[i]+pre[i-1];
        }else pre[i]=a[i];
    }
    ll ans=0;
    rep(i,0,n){
    	ans+=(a[i]%hell * (sum%hell -pre[i]%hell +hell)%hell);
    	ans%=hell;
    }
    pn(ans);

  

}


int main()
{

    _cin
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
    // ll tc;
    // cin>>tc;
    // while(tc--){
    solve();
    // }

}
