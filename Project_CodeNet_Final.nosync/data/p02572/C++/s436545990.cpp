#include<bits/stdc++.h>
#define ll long long 
#define pb push_back
#define bg begin()
#define en end()
#define vvl(n,m) vector<vector<ll> > a( n , vector<ll> (m))
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
ll gcd(ll a,ll b){
    if(a==0)
    return b;
    else
    return gcd(b%a,a);
}
ll maxSubArraySum(ll a[], ll size) 
{ 
    ll max_so_far = -1000000000000000, max_ending_here = 0; 
  
    for (ll i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
ll countPairs(ll arr[], ll n) 
{ 
    map<ll, ll> map; 
    for (ll i = 0; i < n; i++) {
        if (map.find(arr[i]-i) == map.end()) { 
            map[arr[i]-i] = 1; 
        } 
        else { 
            map[arr[i]-i]++; 
        } 
    }
    ll res = 0; 
    for (auto x : map) { 
        ll cnt = x.second; 

        res += ((cnt * (cnt - 1)) / 2); 
    } 
  
    return res; 
} 
ll findSubarraySum(ll arr[], ll n, ll sum) 
{ 
    unordered_map<ll, ll> prevSum; 
  
    int res = 0; 
  
    int currsum = 0; 
  
    for (int i = 0; i < n; i++) { 
        currsum += arr[i]; 
        if (currsum == sum)  
            res++;         
  
        if (prevSum.find(currsum - sum) !=  
                                  prevSum.end())  
            res += (prevSum[currsum - sum]);
        prevSum[currsum]++; 
    } 
  
    return res; 
} 
ll sod(ll x){
    ll r,sum=0;
    while(x>0){
        r=x%10;
        x/=10;
        sum+=r;
    }
    return sum;
}
long long modpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main()
{
    fast
    ll n,i;
    cin>>n;
    ll a[n],sum=0;
    for(i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    ll r=1e9+7;
    ll s=(1e9+8)/2;
    ll z=((sum%r)*(sum%r))%r;
    ll x=0;
    for(i=0;i<n;i++){
        x=(x+(a[i]*a[i])%r)%r;
    }
    x=((z-x)%r+r)%r;
    x=(x*s)%r;
    cout<<x;
}