#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
#include <cmath>
using namespace std;
#define vsort(vec) sort(vec.begin(), vec.end())
#define vreverse(vec) reverse(vec.begin(), vec.end())
using ll =long long;
using ull =unsigned long long;
const ll INF =1001001001;

//10億7。　　　100000007

//最大公約数
ll gcd(ll a, ll b){
   if (a%b==0){
       return(b);
   }else{
       return(gcd(b,a%b));
   }
}
//最小公倍数
ll lcm(ll a, ll b){
   return a*b/gcd(a,b);
}


int main(){
cout<<fixed<<setprecision(10);
//cin.tie(0); ios::sync_with_stdio(false);

int A;
  cin>>A;
  int ans=0;
  ans=A*800-A/15*200;
  cout<<ans<<endl;
  

  
  
}

