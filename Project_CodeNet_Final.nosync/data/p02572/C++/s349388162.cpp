#include<iostream>
#include<vector>
#define ll long long 
#define MOD 1000000007
using namespace std;
 
int main(){
  
  int n;
  cin>>n;
  
  vector<ll> input(n);
  ll sum=0;
  
  for(int i=0;i<n;i++){
    cin>>input[i];
   sum= (sum+input[i])%MOD; 
  }
  ll leftsum=0, ans=0;
  for(int i=0;i<n;i++){
    sum-=input[i];
    if(sum<0) sum+=MOD;
    ans= (ans+ (sum*input[i])%MOD)%MOD;
  }
cout<<ans;  
 
}