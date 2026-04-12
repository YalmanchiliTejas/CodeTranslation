#include<bits/stdc++.h>
#define pb push_back 
 #define fo(i,n) for(int i=0;i<n;i++)
#define ll long long 
#define int long long 
#define Mod 1000000007 
#define MAX 4294967296  // 2^32
const int M=1e9+7;
#define ip pair<int,int>
#define test(t) ll t;cin>>t;while(t--)
  
using namespace std;
void solve(){
int n;
cin>>n;
int a[n];
int ans=0;
int sum=0;

fo(i,n){
    cin>>a[i];
sum+=a[i];
}
fo(i,n){
   sum-=a[i];
   ans+=((sum%Mod)*(a[i]%Mod))%Mod;
}


cout<<ans%Mod;


}

signed main(){


    // std::string binary = std::bitset<8>(n).to_string();
    ios::sync_with_stdio(0);
    cin.tie(0);
  solve();
  


}