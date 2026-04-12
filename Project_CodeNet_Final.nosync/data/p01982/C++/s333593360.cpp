#include <bits/stdc++.h> 
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<=n;i++)
typedef long long ll;ll MM = 1000000000;ll mod = MM + 7;

int main(){
  while(1){
  int n,l,r,cnt=0; cin>>n>>l>>r;
  if(n==0&&l==0&&r==0) break;
    vector<int>a(n);
  rep(i,n) cin>>a.at(i);
  
    for(int i=l;i<=r;i++){
 for(int k=0;k<n;k++){
   
   if(i%a.at(k)==0){
  if((k+1)%2==1) cnt++;
  break;
  }
 
   else if(k==n-1) {
 if(n%2==0) cnt++;
   break;
 }
   
 }
  }
    
   cout<<cnt<<endl; 
  }
}
