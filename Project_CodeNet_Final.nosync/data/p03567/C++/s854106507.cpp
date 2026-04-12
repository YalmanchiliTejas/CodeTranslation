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
#define pb(b) push_back(b) 
#define all(a) a.begin(),a.end()
#define llvec vector<vector<ll>>
#define charvec vector<vector<char>>
#define size(a,b) (a,vector<ll>(b))
const int mod=1e9+7;
/* 
UnionFind：素集合系管理の構造体(union by size)
isSame(x, y): x と y が同じ集合にいるか。 計算量はならし O(α(n))
unite(x, y): x と y を同じ集合にする。計算量はならし O(α(n))
treeSize(x): x を含む集合の要素数。
*/
struct UnionFind{
 vector<int>size,parents;
 UnionFind(){}
 UnionFind(int n){//make n trees.
  size.resize(n,0);
  parents.resize(n,0);
  for(int i=0;i<n;i++)makeTree(i);
 }
 void makeTree(int x){
   parents[x]=x;//the parent of x is x
   size[x]=1;
  }
 bool isSame(int x,int y){return findRoot(x)==findRoot(y);}
 bool unite(int x,int y){
  x = findRoot(x);
  y = findRoot(y);
  if(x==y)return false;
  if(size[x]>size[y]){
   parents[y]=x;
   size[x]+=size[y];
  } 
  else{
   parents[x]=y;
   size[y]+=size[x];
  }
  return true;
 }
 int findRoot(int x){//木の根を探す,計算量削減のため低く
  if(x!=parents[x])parents[x]=findRoot(parents[x]);
  return parents[x];
 }
 int treeSize(int x){return size[findRoot(x)];}
};
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
/*桁数*/ll dig(ll n){ll d=0,tmp=n;while(tmp/10>0){tmp/=10;d++;}return d;}
/*迷路移動*/const int dx[4]={1,0,-1,0};const int dy[4]={0,1,0,-1};
llfor;////////////////////////////////////////////////////////////
int main(){
 string s;cin>>s;
  
 ll n=s.length();
 rep(i,0,n-1){
  if(s[i]=='A'&&s[i+1]=='C'){
   py;
   return 0;
  }
 }
 pn;
return 0;}