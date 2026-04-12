/*
___ is a raging sadist.
*/
//Destroy all WA at test 2
// Stay cool
// Pass the 4th wall..

#include <bits/stdc++.h>
#define fastio()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)
#define pb push_back
#define show(x) cout << (#x) << " : " << x << endl;
#define ll long long
#define ld long double
#define pow power
#define mp make_pair
#define ff first
#define ss second
#define pii pair<ll, ll>
#define sq(x) ((x) * (x))
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define siz(a) int((a).size())
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define endl "\n"
#define pi 3.14159265
const ll mod = 1000 * 1000 * 1000 + 7;
const ll mod1 = 998244353;
const ll INF     = 1ll*1000*1000*1000*1000*1000*1000 + 7; 
using namespace std;

ll power(ll x, ll y) 
{ 
   ll res = 1;      
  
   
    while (y > 0) 
    { 
       
        if (y & 1) 
            res = (long long)(res*x); 
  

        y = y>>1; 

        if (x<=100000000)
        x = (long long)(x*x);

        //cout<<x<<'\n'; 
    } 
    return res; 
} 






int main()
{

#ifndef ONLINE_JUDGE    
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif

fastio();

    ll n;
    cin>>n;

    if (n>=30)
        cout<<"Yes";
    else
        cout<<"No";

return 0;
}