#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define ios ios_base::sync_with_stdio(0) ; cin.tie(0) ; cout.tie(0)
#define so sizeof
#define pb push_back
#define vl vector<ll>
#define endl endl;cf
#define be begin()
#define sz size()
#define en end()
#define all(x) (x).be , (x).en
#define rall(x) (x).rbegin() , (x).rend()
#define acc(x) accumulate((x).be , (x).en , 0)
#define forn(i,a,b) for(ll i=1;i<=b;++i)
#define forr(i,a,b) for(ll i=0;i<b;++i)
#define ro return 0
#define rngx mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define vll vector<pair<ll,ll> >
#define pll pair<ll,ll>
#define plll pair<ll,pair<ll,ll>>
#define plvl pair<pair<ll,ll> ,ll>
#define mp make_pair
#define cf cout.flush()
int main()
{
    ios;
    ll x;
    cin >> x ;
    if(x == 7 or x == 5 or x == 3){
        cout <<"YES\n";
        ro;
    }
    else cout <<"NO\n";
    ro;
}
