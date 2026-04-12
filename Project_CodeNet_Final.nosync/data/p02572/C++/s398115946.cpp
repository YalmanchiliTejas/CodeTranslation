#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll int n, i, s=0, sum=0, p;
    cin>>n;
    ll int arr[n];
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    
    for(i=0; i<n-1; i++){
        s= (s+ arr[i])%1000000007;
        p = (arr[i+1]*s)%1000000007;
        sum=(sum + p)%1000000007;
    }
    cout<<sum;
}