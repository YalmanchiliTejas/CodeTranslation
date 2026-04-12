#define _LIBCPP_DEBUG 0
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll MOD = 1e9+7;

int main(void) {

    int n; cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin>>a[i];

    if(n%2==0){
        for (int i = n-1; i >= 1; i-=2) cout<<a[i]<<" ";
        for (int i = 0; i < n; i+=2) cout<<a[i]<<" ";
    }else{
        for (int i = n-1; i >= 0; i-=2) cout<<a[i]<<" ";
        for (int i = 1; i < n; i+=2) cout<<a[i]<<" ";
    }

    return 0;
}