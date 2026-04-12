#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;

int main(){
    int n;
    cin>>n;
    vector<int> h(n);
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        int m=0;
        for(int j=0; j<i; j++){
            m=max(m,h[j]);
        }
        if(h[i]>=m)cnt++;
    }
    cout<<cnt;
    return 0;
}