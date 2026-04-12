#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef pair<ll,ll> P;
#define fi first
#define se second
set<string> c;
map<ll,ll> mp;
const ll inf=(1e18);
const ll mod=1000000007;
const ll mod2=998244353;
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
ll dp[100005];
int main(){
   int n;
   cin>>n;
   vector<ll> a(n);
   for(int i=0;i<n;i++)cin>>a.at(i);
   fill(dp,dp+n,inf);
   for(int i=n-1;i>=0;i--){
     *upper_bound(dp,dp+n,a.at(i))=a.at(i);
}
cout<<lower_bound(dp,dp+n,inf)-dp<<endl;
}