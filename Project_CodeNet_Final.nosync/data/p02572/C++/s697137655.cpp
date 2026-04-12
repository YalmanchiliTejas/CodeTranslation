#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using namespace std;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n; 
    vector<long long int> vec(n);
    for(int i=0;i<n;++i) cin >> vec[i];
    vector<long long int> pre(n);
    pre[0] = vec[0];
    for(int i=1;i<n;++i) pre[i] = (pre[i-1] + vec[i])%1000000007;
    long long int res = 0;
    for(int i=1;i<n;++i){
        res = ( res%1000000007 + ((long long int)vec[i]*pre[i-1])%1000000007 ) % 1000000007;
    }
    cout << res << '\n';
    return 0;
}