#include<bits/stdc++.h>
typedef long long int LL;
typedef long double dd; 
#define endl "\n"
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
LL dp[2000001];
LL mod=1e9+7;
using namespace std;
bool isPrime(LL n) {
  LL j; 
  for( j=2;j<=sqrt(n);j++){
    if(n%j==0){
      break;  
    } 
  }
  if(j>sqrt(n)){
    return 1; 
  }
  else{
    return 0; }
}
 void solve(LL k){
 LL n; 
 cin>>n; 
 if(n>=30){
   cout<<"Yes"<<endl; 
   return;
 }
cout<<"No"<<endl; 
 }
int main(){
  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// LL t;
//cin>>t;
 LL k=1;
//while(k<=t){
   solve(k);
//  k++;
 // }
   return 0;
   }