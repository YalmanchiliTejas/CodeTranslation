#include <bits/stdc++.h>
#define rep(i,n) for(long long i=0; i<n; i++)
#define Rep(i,n) for(long long i=1; i<n; i++)
#define ll long long
#include <math.h>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <set>
#include <vector>


using namespace std;
#define PI acos(-1)
using P =pair<ll,ll>;

ll ketasu(ll a){
   ll num=1;
   while(a/10){
       num++;
       a/=10;
   }
   return num;
}

ll gcd(ll a,ll b){return b ? gcd(b,a%b) :a;}
ll lcm(ll a,ll b){return a*b/gcd(a,b);}

ll kosuu(ll a){
    ll sum=0;
    for(ll i=1;i*i<=a;i++){
        if(a%i==0){
            if(a!=1&&i*i!=a){
            sum+=2;
            }else{
             sum++;   
            }
        }
    }
    return sum;
}

ll n;



    vector<pair<ll,ll>>p;
void fs(ll a){
    for(ll i=2;i*i<=n;i++){
        ll cnt=0;
        while(n%i==0){
            n/=i;
            cnt++;
        }
        p.emplace_back(i,cnt);
    }
    return;
}


ll di[]={1,0,-1,0};
ll dj[]={0,-1,0,1};
int main(){
   int n;
   cin>>n;
    long long int a[n],ans=0,i;
    int mod=1000000007;
    long long int sum=0;
 
    for( i = 0 ; i < n ; i++ ){
            cin>>a[i];
    }
    rep(i,n)sum+=a[i];
    for( i = 0 ; i < n ; i++ ){
        sum = sum - a[i];
 
        ans+=(sum%mod * a[i]%mod)%mod;
    }
    cout<<ans%mod;
 
    return 0;
}
 


