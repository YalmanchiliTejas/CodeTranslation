#include <bits/stdc++.h>
#define ll long long int
#include<list>
#include<algorithm>
#define ld long double
#define pb push_back
#define FF first
#define SS second
#define rep(a,b,c) for(a=b;a<c;a++)
#define repr(a,b,c) for(a=b-1;a>=c;a--)
#define PLL pair<ll, ll>
#define inf 100000001
#define mod 1000000007
#define LB lower_bound
#define UB upper_bound
#define MP make_pair
#define PQ priority_queue
#define rep1 for(i=1;i<=n;i++)
#define VLL vector<ll>
#define EF else if
const double pi  =3.141592653589793238463;
#define all(x) (x).begin(), (x).end()
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());
#define UMP unordered_map
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define test1(x)                cerr<<#x<<": "<<x<<endl
#define test2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define test3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define test4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define test5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define test6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
using namespace std;
/*
    //string with spaces
    std::string str;
    std::getline(std::cin >> std::ws, str);
*/
ll myXOR(unsigned long long int x, unsigned long long int y)
{
    return (x|y)&(~x|~y);   
}
ll powerLL(ll x, ll n) 
{ 
    ll result = 1; 
    while (n) { 
        if (n & 1) 
            result = result * x % mod; 
        n = n / 2; 
        x = x * x % mod; 
    }
    return result; 
}
int main()
{
    fastio
    ll a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r, t,u,w,x,y,z;
    string str, ss, str1;
    cin>>n;
    ll arr[n];
    rep(i,0,n){
        cin>>arr[i];
    }
    ll sum[n];
    sum[n-1] = arr[n-1];
    for(i=n-2;i>=0;i--){
        sum[i] = (sum[i+1]%mod+arr[i]%mod)%mod;
    }
    ll res=  0;
    rep(i,0,n-1){
        res = (res%mod + (arr[i]%mod*sum[i+1]%mod)%mod)%mod;
    }
    cout<<res;
}