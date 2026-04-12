#pragma GCC optimize("O3")
#include<bits/stdc++.h> 
using namespace std;
using ll=long long;
typedef  unsigned long long int ull;
typedef pair<ll,ll> P;
template<class T> using V=vector<T>; 
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
const ll inf=(1e18);
//const ll mod=998244353;
const ll mod=1000000007;
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
ll gcd(ll a,ll b) {return b ? gcd(b,a%b):a;}
ll lcm(ll c,ll d){return c/gcd(c,d)*d;}
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int main(){
ll n;
cin>>n;
V<ll> a(n);
ll ans=0;
for(int i=0;i<n;i++){
   cin>>a[i];
}
sort(all(a));
int mid=n/2;
V<ll> b(n);
b[mid]=a[0];
int l=1,r=n-1;
for(int i=1;i<=mid;i++){
    if(i%2==1){
        b[mid-i]=a[r--];
        if(mid+i<n)b[mid+i]=a[r--];
    }
    else{
        b[mid-i]=a[l++];
        if(mid+i<n)b[mid+i]=a[l++];
    }
}
ll res=0,res2=0;
for(int i=0;i<n-1;i++){
  res+=abs(b[i+1]-b[i]);
}
b[mid]=a[n-1];
l=0;r=n-2;
for(int i=1;i<=mid;i++){
    if(i%2==0){
        b[mid-i]=a[r--];
        if(mid+i<n)b[mid+i]=a[r--];
    }
    else{
        b[mid-i]=a[l++];
        if(mid+i<n)b[mid+i]=a[l++];
    }
}
for(int i=0;i<n-1;i++){
  res2+=abs(b[i+1]-b[i]);
}
cout<<max(res,res2)<<endl;
}

