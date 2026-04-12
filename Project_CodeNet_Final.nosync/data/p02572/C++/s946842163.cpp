#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    long long dekai=1000000007,ans=0,sum=0;
    vector<long long> a(n);
    for(long long i=0;i<n;i++){
        cin >> a.at(i);
    }
    for(long long i=0;i<n;i++){
        ans+=(sum*a.at(i)%dekai);
        ans%=dekai;
        sum+=(a.at(i)%dekai);
        sum%=dekai;
    }
    cout << ans << endl;
    return 0;
}