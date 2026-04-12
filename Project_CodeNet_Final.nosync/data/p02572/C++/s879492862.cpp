#include <bits/stdc++.h> 
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    long long q(1);//cin>>q;
    while(q--){
        long long n,mod(1e9+7),tot(0);cin>>n;long long arr[n],sum[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(i==0) sum[i]=arr[i];
            else sum[i]=(arr[i]+sum[i-1]);
        }
        for(int i=0;i<n-1;i++){
            tot+=arr[i]*((sum[n-1]-sum[i])%mod);
            tot%=mod;
        }
        cout<<tot<<endl;
    }
    return 0;
}