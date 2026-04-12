/**So..a**/
#include<bits/stdc++.h>

using namespace std;
#define FAST ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define PB(x, v) x.push_back(v);
#define M_P(a, b) make_pair(a, b)
#define pll pair<ll, ll>
#define ll long long
#define mll map<ll, ll>
#define vl vector<ll>
#define fa(x, v) for(auto x: v)
#define fr(i, a, b) for(int i= a;i <=b; i++)
#define TEST  ll Test; cin >> Test; while(Test--)

#define B_ begin()
#define E_ end()
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define NL_ "\n"
#define F first
#define S second
#define FF first.first
#define FS first.second
#define SF second.first
#define SS second.second

#define mod(a) a%1000000007
#define MAX 2000000000
#define  ull unsigned long long
 string s, t;

 ll atleast(ll& i)
 {
     if(s.length()-i <t.length())  return LLONG_MAX;
     ll len = 0;
     for(ll j = 0; j<t.length(); j++)
     {
           if(s[i+j]==t[j]) continue;
           len++;
     }
     return len;
 }



int main()
{

    FAST;
    ll n;
    cin >> n;
   ll arr[n+1];
    arr[0];
    ll r;
    fr(i ,1, n)
    {
        cin >> r;
        arr[i] = arr[i-1] + r;
    }
    const ll mod = 1000000000+7 ;
    ll ans = 0;
    fr(i, 1, n-1)
    {
        r = arr[i] - arr[i-1];
        ll temp  = arr[n] - arr[i];
        temp%=mod;
        r*=temp;
        r%=mod;
        ans+=r;
        ans%=mod;
    }
    cout << ans%mod;

    return 0;
}
