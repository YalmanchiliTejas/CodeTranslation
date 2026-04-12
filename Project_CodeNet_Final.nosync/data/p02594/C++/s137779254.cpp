#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
#define endl "\n"
#define nl cout<<endl
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
#define txti freopen("input.txt", "r", stdin);
#define txto freopen("output.txt", "w", stdout);
//#define mod 100000007

#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 

bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.second > b.second )
        return true;
    if( a.second==b.second && a.first > b.second )
       return true;
 
    return false;
 }
//me
ll const mod = 1e9+7;
ll const inf = 1e6+2;
ll fact[inf];
void factfill()
{
    fact[0]=1;
    for(ll i=1; i<inf; i++)
        fact[i] = ( fact[i-1]*i ) % mod;
}

ll powmod(ll a, ll b)
{
    ll res = 1;
    while(b){
        if(b%2) res = ( res*a )%mod;
        a = (a*a)%mod;
        b/=2;
    }
    return res;
}

ll inv(ll x)
{
    return powmod(x,mod-2) % mod;
}

ll choose(ll n, ll r)
{
    return ( (fact[n]* inv(fact[n-r] ) )%mod *inv(fact[r]))%mod;
}
void solve()
{   

   ll n; cin >> n;

   if(n>=30)
    cout << "Yes";
else
    cout << "No";
}

int main() {
Knucklehead 
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/


        //factfill();
        ll t;
        /**/t=1;
        /*/cin>>t;/**/
        f(testcases,0,t){
            solve();
        }
 
 
 
 
    return 0;
}