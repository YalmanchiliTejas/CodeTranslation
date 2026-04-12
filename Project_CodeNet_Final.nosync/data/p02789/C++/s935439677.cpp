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
#define all(a) a.begin(),a.end()
#define f(i,a,b) for(int i=a;i<b;i++)
#define MOD 1000000007
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
  int n,m;
  cin >>n>>m;
  if(n==m) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}


