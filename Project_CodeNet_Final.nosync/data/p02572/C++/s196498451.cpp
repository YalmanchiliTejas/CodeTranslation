#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
#define endl "\n"
using namespace std;

int mod=1e9+7;

int power(int x,int n,int mod){
    //(x^n)%mod
    int result=1;
    while(n){
        if(n%2)
            result=(result*x)%mod;
        x=(x*x)%mod;
        n/=2;
    }
    return result;
}

int inverseMod(int x,int mod){
    return power(x,mod-2,mod);
}


int32_t main() {

    fast

    int n;
    cin>>n;

    vector<int>arr(n);
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
        sum%=mod;
    }
    int curr;
    int ans=0;
    int currSum=0;
    for(int i=0;i<n;i++){
        currSum+=arr[i];
        currSum%=mod;
        curr=(sum-currSum+mod)%mod;
        int toadd=(curr*arr[i])%mod;
        ans+=toadd;
        ans%=mod;
    }
    cout<<ans;


    return 0;
}

