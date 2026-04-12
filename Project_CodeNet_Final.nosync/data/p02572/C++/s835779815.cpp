#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<stack>
#include<algorithm>

using namespace std;

void slove(){
    int n;
    cin>>n;
    vector<long long> arr(n);
    for(int i = 0; i < n; ++i){
        cin>>arr[i];
    }

    vector<long long> prefix(n+1,0);
    long long mod = 1e9 + 7;
    long long ans = 0;
    for(int i = 1; i <= n; ++i){
        prefix[i] = (prefix[i-1] + arr[i-1])%mod;
    }
    for(int i = 1; i <= n; ++i){
        ans = (ans + (arr[i-1]*(prefix[n] - prefix[i] + mod)%mod))%mod;
    }
    cout<<ans<<endl;
}

int main(){
    slove();
}
