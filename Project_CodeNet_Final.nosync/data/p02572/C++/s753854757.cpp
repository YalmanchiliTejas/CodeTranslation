#include<bits/stdc++.h>
#define NUM 1000000007
using namespace std;

typedef long long unsigned llu;

int main(){
    llu n,sum=0;
    cin>>n;
    llu arr[n];
    
    for(llu i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    llu res=0;
    for(llu i=0;i<n;i++){
        sum-=arr[i];
        llu temp = ((sum%NUM)*arr[i])%NUM;
        res = (temp + res)% NUM;
    }   
    cout<<res<<endl;
    
}