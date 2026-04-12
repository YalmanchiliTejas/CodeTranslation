#include<bits/stdc++.h>
#define ll long long int
#define pragi(a,b) for(ll i = a;i<b;i++)
#define pragj(a,b) for(ll j = a;j<b;j++)
#define pragk(a,b) for(ll k = a;k>=b;k--)
#define all(v) (v.begin(),v.end())
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define MP make_pair
#define MT make_tuple
#define F first
#define S second
#define KAKA ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
const int mod = 1e9 + 7;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long double ld;
typedef pair<int, int> pii;
//typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;

void Compute(ll n,ll x,ll m)
{
    KAKA
    vector<ll> vec;
    vec.eb(x);
   
    bool ok = false;
    vector<ll> rem(m,-1);
     rem[x] = 0;
    ll repeater = -1;
    ll repstrt = -1;
    //if(n <= 100000)
    pragi(0,min(n - 1,m + 1))
    {
        ll prev = vec.back();
        ll nxt = ((prev % m) * (prev % m))%m;
        if(rem[nxt] == -1)
        {
            vec.eb(nxt);
            rem[nxt] = vec.size() - 1;
        }
        else
        {
            repeater = vec.size() - rem[nxt];
            repstrt = rem[nxt];
            ok = true;
            break;
        }
        
    }
    //cout<<repstrt<<"\n";
    ll sum = 0;
    for(auto ele : vec)
    {
        //cout<<ele<<" ";
      sum += ele;
    }
   // cout<<"\n";
    if(ok){
    ll rept_sum = 0;
    pragi(repstrt,vec.size())
    {
        rept_sum += vec[i];
    }
    ll rem_terms = n - vec.size();
    ll q = rem_terms/repeater;
    ll r = rem_terms % repeater;
    sum += (q * rept_sum);
    pragi(repstrt,repstrt + r)
    {
        sum += vec[i];
    }}
    cout<<sum<<"\n";
}
int main()
{
    KAKA
    ll n,x,m;
    cin>>n>>x>>m;
    Compute(n,x,m);
}