#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define f(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
ll n;
ll a[10000];

ll dp[3100][3100];
ll find(ll i,ll j){
if(i>j){
  return 0;
 }
if(dp[i][j]!=-1){
  return dp[i][j];
}
ll c1=a[i]+min(find(i+1,j-1),find(i+2,j));
ll c2=a[j]+min(find(i+1,j-1),find(i,j-2));
return dp[i][j]=max(c1,c2);
}
int main(){
cin>>n;
ll sum=0;
f(i,0,n){
  cin>>a[i];
  sum+=a[i];
}
f(i,0,n+2){
  f(j,0,n+2){
    dp[i][j]=-1;
  }
}
cout<<2*find(0,n-1)-(sum);

}