#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define perl(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define pb push_back
#define ins insert
#define all(x) (x).begin(),(x).end()
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9+10;
const ll INF=4e18;
const ll dy[8]={1,0,-1,0,1,1,-1,-1};
const ll dx[8]={0,-1,0,1,1,-1,1,-1};
using Graph = vector<vector<int>>;
const ll mod=1000000007;
const int MAX_N = 1000;         // n の最大値
 
double nCk(int n, int k) {
double res=1.0;
for(int i=0; i<n; i++){
res*=0.5;}
for(int i=0; i<k; i++){
res*=(double)(n-i);
res/=(double)(k-i);
}
return res;}
 
int main() {
ll n;
cin>>n;
ll a[n]={};
ll ans=0;
ll ans1=0;
ll b[n]={};
ll ca;
for(ll i=0; i<n; i++){
cin>>a[i];
b[i]=a[i];}
sort(a,a+n);
sort(b,b+n);
reverse(b,b+n);
if(n%2==1){
ca=a[(n-1)/2];
for(ll i=0; i<n/2; i++){
ans+=abs(a[i]-ca);
ca=a[i];
ans+=abs(b[i]-ca);
ca=b[i];}
ca=a[(n-1)/2];
for(ll i=0; i<n/2; i++){
ans1+=abs(b[i]-ca);
ca=b[i];
ans1+=abs(a[i]-ca);
ca=a[i];}
ans = max(ans , ans1);
cout << ans << endl;}
else{
ll ca = a[n/2];
for(ll i=0; i<n/2-1; i++){
ans+=abs(a[i]-ca);
ca=a[i];
ans+=abs(b[i]-ca);
ca=b[i];}
ans+=abs(ca-a[n/2-1]);
cout << ans << endl;}}
