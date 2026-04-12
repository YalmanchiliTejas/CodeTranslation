#include <bits/stdc++.h>
using namespace std;
int mod =1000000007;
int main(){
    int n;
    long long sum=0;
    long long x=0;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        sum = (sum+a[i]*x)%mod;
        x=(x+a[i])%mod;
    }
    cout<<sum<<endl;
    return(0);
}