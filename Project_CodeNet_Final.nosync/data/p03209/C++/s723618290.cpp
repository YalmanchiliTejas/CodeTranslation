#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int m=50;

vector<ll> thick(m+1),patty(m+1);

ll dp(int n,ll x){
  if(x==0){if(n==0) return 1; else return 0;}
  if(x==thick[n]-1) return patty[n];
  if(x==(thick[n]-1)/2) return patty[n-1]+1;
  if(x>(thick[n]-1)/2) return patty[n-1]+1+dp(n-1,x-(thick[n]+1)/2);
  else return dp(n-1,x-1);
  cout << "error";
  return -30000000; 
}
  
int main(){
  int n;
  ll x;
  cin >> n >> x;
  x--;
  
  thick[0]=1;
  patty[0]=1;
  rep(i,n){thick[i+1]=2*thick[i]+3;patty[i+1]=2*patty[i]+1;}
  
  cout << dp(n,x);
  return 0;
}