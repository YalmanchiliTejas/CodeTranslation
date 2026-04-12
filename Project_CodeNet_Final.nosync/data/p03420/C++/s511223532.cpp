#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
 
int main() {
ll n,k;
cin>>n>>k;
ll ca=10000000000;
ll counter=0;
ll a[n]={};
ll cb=10000000000;
if(k==0){
cout<<n*n<<endl;}
else{
for(ll i=k+1;i<=n;i++){
if(n%i>=k){
counter+=n/i*(i-k)+n%i+1-k;}
else
counter+=n/i*(i-k);}
cout<<counter<<endl;}
}