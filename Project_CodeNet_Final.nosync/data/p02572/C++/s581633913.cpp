/*
 * author :Sadik Hassan(_sad_)
 *
*/
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
using   ll =          long long;
using   ld =          long double;
#define nl            "\n"
#define pb            push_back
#define fi            first
#define se            second
#define MP            make_pair
#define PI            (acos(-1.0))
#define rep1(i,n)     for(int i=1;i<=n;i++)
#define rep(i,n)      for(int i=0;i<n;i++)
#define SZ(s)         (int)s.size()
#define all(x)        (x).begin(), (x).end()
#define rall(x)       (x).rbegin(), (x).rend()
#define w(t)          int t;cin>>t;while(t--)
#define TSU(s)        transform(s.begin(),s.end(),s.begin(),::toupper);
#define TSL(s)        transform(s.begin(),s.end(),s.begin(),::tolower);
#define _SAD()     	  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0),cout<<fixed<<setprecision(3);

typedef vector<int> vi;
typedef vector<ll> vii;
typedef set<int> si;
typedef set<ll> sii;
/*---------------------------------------------------------------------*/

const int N = (int)2e5+5;
const ll MOD =(ll)1e9+7;
const ll INF = (ll)1e18+5;
const int nn=1e5+5;

int main()
{
    _SAD()
    int n;
    cin>>n;
    vii a(n);
    ll cnt=0,ans=0;
    rep(i,n)
    {
        cin>>a[i];
        cnt+=a[i];
        ans+=(a[i]*a[i]%MOD);
            cnt%=MOD;
            ans%=MOD;
    }
   ll nt=cnt*cnt%MOD;
   nt-=ans;
   if(nt<0)nt+=MOD;
   (nt*=(MOD+1)/2)%=MOD;
   nt%=MOD;
    cout<<nt<<nl;
    return 0;
}
