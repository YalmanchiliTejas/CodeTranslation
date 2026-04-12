#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a.at(i);
    }
    int mod=1000000007;
    long long sum=0;
    for(long long tmp=0,i=1;i<n;i++){
        tmp+=a.at(i-1);
        tmp%=mod;
        sum+=tmp*a.at(i);
        sum%=mod;
    }
    cout<<sum<<endl;
    return 0;
}