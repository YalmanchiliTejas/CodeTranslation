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
ll const mod = 1e9+7;//998244353;
ll const inf = 1e3+1;

void solve()
{   
    ll n; cin >> n;
    ll a[n]; 
    f(i,0,n) cin >> a[i];

    ll suf[n+1]={0}; suf[n-1]=a[n-1];

    for(ll i = n-2; i>=0; i--)
        suf[i] = (a[i] + suf[i+1])%mod;
    ll ans = 0;
    f(i,0,n){

        ans = (ans + (a[i] * suf[i+1])%mod  )%mod;
        //cout << suf[2] << endl;
    }
    cout << ans << endl;
} 

int main() {
Knucklehead 
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/ 
        
        ll t;
        /**/t=1;
        /*/cin>>t;/**/
        f(testcases,0,t){
            solve();
        }
 
 
    return 0;
}
