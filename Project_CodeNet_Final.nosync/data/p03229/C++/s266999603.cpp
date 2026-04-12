#include<stdio.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<functional>
#include<limits.h>
#include<stdlib.h>
#include<cmath>
#include<cstring>
#include<set>
#include<climits>
using namespace std;

#define intmax INT_MAX
#define lmax LONG_MAX
#define uintmax UINT_MAX
#define ulmax ULONG_MAX
#define llmax LLONG_MAX
#define ll long long
#define rep(i,a,N) for((i)=(a);(i)<(N);(i)++)
#define rrp(i,N,a) for((i)=(N)-1;(i)>=(a);(i)--)
#define llfor ll i,j
#define sc(a) cin>>a
#define pr(a) cout<<a<<endl
#define pY puts("YES")
#define pN puts("NO")
#define py puts("Yes")
#define pn puts("No")
#define pnn printf("\n")
#define all(a) a.begin(),a.end()
#define push(a,b) (a).push_back(b)
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
#define llpvec vector<pair<ll,ll>>
/*pi*/const double pi=acos(-1);
/*繰り上げ除算*/ll cei(ll x,ll y){ll ans=x/y;if(x%y!=0)ans++;return ans;}
/*最大公約数*/ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
/*最小公倍数*/ll lcm(ll x,ll y){return x/gcd(x,y)*y;}
/*n乗*/ll llpow(ll x,ll n){ll i,ans=1;rep(i,0,n)ans*=x;return ans;}
/*階乗*/ll fact(ll x){ll i,ans=1;rep(i,0,x)ans*=(x-i);return ans;}
/*nCr*/ll ncr(ll n,ll r){return fact(n)/fact(r)/fact(n-r);}
/*nPr*/ll npr(ll n,ll r){return fact(n)/fact(n-r);}
/*primejudge*/bool prime(ll a){if(a<=1)return false;ll i;for(i=2;i*i<=a;i++){if(a%i==0)return false;}return true;}
/*Fibonacci数列*/ll fib(ll x){ll i,fibo[x+10];fibo[0]=1;fibo[1]=1;fibo[2]=1;rep(i,3,x+1)fibo[i]=fibo[i-1]+fibo[i-2];return fibo[x];}
/*桁数*/ll dig(ll n){ll d=0,i=0;while(n/10>0){i++;d++;}return d;}
/*迷路移動*/const int dx[4]={1,0,-1,0};const int dy[4]={0,1,0,-1};
llfor;//ll ans=0;////////////////////////////////////////////////////////////
int main(){
 ll n;
 cin>>n;
  
 vector<ll>a;
 ll b;
 rep(i,0,n){
  cin>>b;
  push(a,b);
 }
 sort(all(a));
  
 vector<ll>al1;//初めに大きいほうを持ってくる
 rep(i,0,n){
  if(i==0){
   push(al1,1);
   continue;
  }
  if(i%2==0){
   if(i!=n-1)push(al1,2);
   else push(al1,1);
  }
  else {
   if(i!=n-1)push(al1,-2);
   else push(al1,-1);
  }
 }
 sort(all(al1));
 ll t1=0;
 rep(i,0,n){
  t1+=al1[i]*a[i];
 }
  
 vector<ll>al2;//初めに小さいほうを持ってくる
 rep(i,0,n){
  if(i==0){
   push(al2,-1);
   continue;
  }
  if(i%2==1){
   if(i!=n-1)push(al2,2);
   else push(al2,1);
  }
  else {
   if(i!=n-1)push(al2,-2);
   else push(al2,-1);
  }
 }
 sort(all(al2));
 ll t2=0;
 rep(i,0,n){
  t2+=al2[i]*a[i];
 }  
 ll ans=max(t1,t2);
 pr(ans);
 return 0;}