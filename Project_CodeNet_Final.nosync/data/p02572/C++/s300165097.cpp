#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define For(i,a,b) for(long long i=a;i<b;i++)
#define pb push_back
using namespace std;
typedef long long ll;
ll power(ll x,ll y,ll p){
ll res = 1;x = x % p;
while (y > 0){
if (y & 1){res = (res*x) % p;}
y = y>>1;
x = (x*x) % p;}
return res;}
ll mcd(ll a,ll b){
    if(b>a)swap(a,b);
    if(b==0)return a;
    else return mcd(b,a%b);
}
ll n,m,k;
bool esprimo(ll n){
ll s=0;
for(ll i=1;i*i<=n;i++){
    if(n%i==0){s++;}}
if(s>=2){return false;}
return true;
}
int main(){
    //    cout<<fixed<<setprecision(2);
//cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
 cin>>n;
 ll a[n];
 ll s=0;
 for(int i=0;i<n;i++){cin>>a[i];s+=a[i];s%=(ll)(1e9+7);}
 ll ans=0;
 for(int i=0;i<n;i++){
    s-=a[i];
    s+=1e9+7;
    s%=(ll)(1e9+7);
    ans+=s*a[i];
    ans%=(ll)(1e9+7);
 }

 cout<<ans<<endl;

}
