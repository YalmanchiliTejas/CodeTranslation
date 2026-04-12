#include <bits/stdc++.h>
using namespace std;
#define ll long long int
 
#define vl vector<ll>
#define vi vector<int>
 
#define ff first
#define ss second
 
#define pb push_back
#define MOD 1000000007
//const int nax = 1e6+5;
#define inf 4e18
 
#define display(v) for(int i =0;i<v.size();++i)cout << v[i] << " "
#define all(v) v.begin(),v.end()
ll sqr(ll x){return x*x;}
inline ll add(ll a, ll b){ ll c = a + b; if(c >= MOD) c -= MOD; return c; }
inline ll mul(ll a, ll b){ return (a * 1ll * b) % MOD; }
inline ll sub(ll a, ll b){ ll c = a - b; if(c < 0) c += MOD; return c; }
const int nax = 200*1000 + 10;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 
   int x; cin>>x;
   if(x>=30)cout << "Yes";
   else cout << "No\n";

  
    return 0;
}
    

// Химаншу
