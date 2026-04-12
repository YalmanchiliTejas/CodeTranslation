#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n;
    ll r=1e9+7;
    cin>>n;
    ll arr[n];
    ll sum=0;
    for(int i=0;i<n;i++){
        ll temp;
        cin>>temp;
        if(i==0)
            arr[i]=temp;
        else{
            sum+=(temp*arr[i-1])%r;
            arr[i]=(arr[i-1]%r+temp%r)%r;
        }
    }


    cout<<sum%r;
    return 0;
}
