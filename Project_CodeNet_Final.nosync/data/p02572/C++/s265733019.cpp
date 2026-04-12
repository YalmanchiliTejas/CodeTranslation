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
int main()
{
 const ll m=1000000007;
 ll n;
 cin>>n;
 vector<ll>a(n);
 rep(i,n)cin>>a[i];
 vector<ll>v(n-1);
 ll sum=0;
 Rep(i,n)sum+=a[i];
 v[0]=sum%m;
 Rep(i,n-1){
     v[i]=(v[i-1]-a[i]);
     v[i]=v[i]%m;
     if(v[i]<0)v[i]+=m;
 }  
 ll ans=0;
 rep(i,n-1){
     
         ans+=(a[i]%m * (v[i]%m))%m;
         ans%=m;
 }
 cout<<ans<<endl;
 
}
 


