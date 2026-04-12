#include<bits/stdc++.h>

using namespace std;

using u128 = __uint128_t;

#define int long long
#define mod 1000000007

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    if(n==0) cout<<0<<endl;
    else {
        if(n==m){
            cout<<"Yes"<<endl;
        } else cout<<"No"<<endl;
    }
}