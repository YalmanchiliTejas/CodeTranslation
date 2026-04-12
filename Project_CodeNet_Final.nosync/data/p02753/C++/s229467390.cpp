#include <bits/stdc++.h>
#include <math.h>
#include <cmath>

using namespace std;
using ll =long long;
using vi = vector<int>; 
using vvi = vector<vi>; 
using vl = vector<ll>; 
using vvl = vector<vl>; 

#define rep(i,n) ;for( int i =0; i < n ; i ++)

bool is_int_lround(double x){
  return std::lround(x)==x;
}
int ketasuu(int x){
  int n=0;
  while(x>0){
    x /=10 ;
    n ++;
  }
  return n;
}
ll gcd11(ll x, ll y){
  long long a= max(x,y), b=min(x,y), c=a%b;
  while( c!=0){
    a =b;
    b =c;
    c = a%b;
  }
  return b;
}

int abs(int x, int y){
  if(x>=y){
    return x-y;
  }
  else if(y>x){
    return y-x;
  }
}
int fiv(int n){
  if(n==0){
    return 0;
  }
  else if(n==1){
    return 1;
  }
  return fiv(n-1)+fiv(n-2);
}
ll conbi(int n,int m){
  
  cin>>n>>m;
  vector<ll> a(100);
  a[0] =1;
  for(int i=0;i<14;i++){
    a[i+1]=a[i]*(i+1);
  }
  return a[n] /(a[m] *a[n-m]);
}
int main(){
  string s;
  cin>>s;
  if(s =="AAA" || s== "BBB"){
    cout <<"No"<<endl;
  }
  else{
    cout <<"Yes"<<endl;
  }
 
  

  
}

