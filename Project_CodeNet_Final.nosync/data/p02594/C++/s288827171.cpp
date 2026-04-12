#include<bits/stdc++.h>
using namespace std;
#include<string.h>

#define vpp vector<pair<int,int>>
#define ll long long int
#define ull unsigned long long
#define ld long double
#define fi(i,a,b) for(ll i=a;i<b;i++)
#define fj(j,a,b) for(ll j=a;j<b;j++)
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define mpi map<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define mpl map<ll,ll>
#define pb push_back
#define MOD 1000000007
#define ub upper_bound
#define lb lower_bound
#define itr(v) for(auto it:v)
#define all(v) v.begin(),v.end()  
#define w(t)  int t; cin>>t; while(t--)
#define fio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
ll fast_pow(ll k, ll p)
{
if (p == 0)
        return 1;
 
    ll P = fast_pow(k, p/2);
    P = (P * P) % MOD;
 
    if (p % 2 == 1)
        P = (P * k) % MOD;
 
    return P;
}
ll invmod(ll a,ll m)
{
    return fast_pow(a,m-2);
}

bool isPrime(ll n) 
{ 
   
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
  
       if (n % 2 == 0 || n % 3 == 0) 
        return false; 
  
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
  
    return true; 
} 
ll nextPowerOf2(ll n)
{
    n>>=1;
    ll count = 0;

    if (n && !(n & (n - 1)))
        return n;

    while( n != 0)
    {
        n >>= 1;
        count += 1;
    }

    return 1 << count;
}

ll binomialCoeff(ll n, ll k) 
{ 
    ll C[k+1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1;
  
    for (ll i = 1; i <= n; i++) 
    {
        for (ll j = min(i, k); j > 0; j--) 
            C[j] = C[j] + C[j-1]; 
    } 
    return C[k]; 
} 


//////////////////////*********CODE***********/////////////////////
int main(){
    int n;
    cin>>n;
    if(n>=30){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;
}