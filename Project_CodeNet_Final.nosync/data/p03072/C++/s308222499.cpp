#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int ncr(int n,int r){ int res=1; if(r>n-r)r=n-r; for(int i=0;i<r;i++) {  res*=n-i;  res/=i+1; } return res; }

int gcd(int a,int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--){
       int n;
       cin>>n;
       int arr[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       int maxh=0;int count=0;
       for(int i=0;i<n;i++){
           if(maxh<=arr[i]){
               maxh=arr[i];
               count++;
           }
       }
       cout<<count;
    }
}
    