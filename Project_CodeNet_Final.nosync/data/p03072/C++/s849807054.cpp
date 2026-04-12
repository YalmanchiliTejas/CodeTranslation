#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const int mod = 1000000007;
ll cnt = 0;
ll gcd(ll x,ll y){
   return y ? gcd( y , x%y ) : x;
}



int main(){
   int n;   cin >> n;
   int a[n],maxhigh;
   rep(i,n)cin >> a[i];

   maxhigh=0;

   for(int i=0;i<n;i++){
       if(maxhigh<=a[i]){
           cnt ++;
           maxhigh = a[i];
       }
   }
   cout << cnt << endl;
   
}