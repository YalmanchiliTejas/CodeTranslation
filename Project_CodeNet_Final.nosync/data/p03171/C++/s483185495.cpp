#include <bits/stdc++.h>
using namespace std;
#define ll long long                  // Short form for long long
#define ld long double                // Short form for long double
typedef pair<ll, ll> pii;              // Pair of long long
typedef vector<ll> vi;                // Vector of long long
typedef vector<vi> vvi;               // Vector of vector of long long
typedef vector<pii> vii;               // Vector of pairs
typedef vector<vii> vvii;             // Vector of vector of pairs
#define pq priority_queue             // Max heap (To convert to min heap, use negative sign before every value)
#define ff first                      // For pairs
#define ss second                     // For pairs
#define pb push_back                  // Pushback to vector
#define mp make_pair                  // Makes pairs to be stored as pair
#define all(c) (c).begin(), (c).end() // Mainly used by me in sorting

ll gcd(ll a,ll b){return b ? gcd(b,a%b) : a;}

vvi adj;
ll n,m,x,y,k;
// vi dp,vis;
ll mod = 1e9 + 7;
ll t=1;

bool isPrime(ll n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
    if (n%2 == 0 || n%3 == 0) return false;   
    for (ll i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false;   
    return true; 
} 

ll max_(ll a,ll b,ll c,ll d){
    return max(max(a,b),max(c,d));
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cin>>t;
    while(t--){
        cin>>n;    
        vi a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        ll dp[n][n];
        for(int l=n-1;l>=0;l--){
            for(int r=l;r<n;r++){
                if(l==r)dp[l][r] = a[l];
                else{
                    dp[l][r] = max(a[l] - dp[l+1][r],a[r] - dp[l][r-1]);
                }                
            }
        }
        cout<<dp[0][n-1];
    }
    return 0;
}    