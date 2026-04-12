#include <iostream>
#include<iomanip>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout<< "YES"<<endl;
#define No cout<< "No"<<endl;
#define Yes cout<< "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn=200000;
ll fac[maxn];
ll rfac[maxn];
ll mod = INF;

ll pow(ll x,ll y){
    if(y==0){
        return 1;
    }else if(y==1){
        return x;
    }else if(y%2==0){
        ll a=pow(x,y/2);
        return (a*a)%mod;
    }else{
        ll a=pow(x,(y-1)/2);
        return a*a%mod*x%mod;
    }
}

int main(){
    
    ll h,w,k;
    ll ans=0;
    
    cin >> h>>w>>k;
    fac[0]=fac[1]=rfac[0]=rfac[1]=1;
    
    for(ll i=1;i<=w;i++){
        ans = (ans+(w-i)*i%mod*(h*h)%mod)%mod;
    }
    
    for(ll i=1;i<=h;i++){
        ans = (ans+(h-i)*i%mod*(w*w)%mod)%mod;
    }
    
    
    
    for(ll i=1;i<=h*w;i++){
        fac[i]=fac[i-1]*i%mod;
    }
    
    rfac[h*w]=pow(fac[h*w],INF-2);
    
    for(ll i=h*w;i>=1;i--){
        rfac[i-1]=rfac[i]*i%mod;
    }
    
    ll comb = fac[h*w-2]*rfac[h*w-k]%mod*rfac[k-2]%mod;
    ans= ans*comb%mod;
    
    cout << ans <<endl;
    
    return 0;
}
