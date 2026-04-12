/*      Author : Kaustubh Gangwar
        Institute : IIITA        */
#include <bits/stdc++.h>
using namespace std;
#define modo 1000000007
#define F first
#define S second 
#define pb push_back
#define gcd __gcd
#define vi vector<int>
#define vll vector<long long>
#define all(x) (x).begin(),(x).end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define fe(i,a,b) for(int i=a;i<=b;i++)
#define CODING ios_base::sync_with_stdio(false); 
#define SAMRAT cin.tie(0),cout.tie(0);
#define mii map<int,int>
#define nl '\n'
typedef long long  ll;
typedef pair<int,int> pii;
 
ll bpow(ll a, ll b) {
    a=a; ll ans = 1;
    while(b){
        if (b & 1)
        ans = ans * a;
        a = a * a;
        b >>= 1;
    }
    return ans;
}

int32_t main()
{ 
   CODING SAMRAT
   int test=1;
 //  cin>>test;
   while(test--)
   {
    ll n;
    cin>>n;
    if(n>29)
    cout<<"Yes\n";
    else cout<<"No\n";
   }

return 0;
}