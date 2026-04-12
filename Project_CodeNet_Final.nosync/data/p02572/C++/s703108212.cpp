#include <bits/stdc++.h>
using namespace std;

const int mod=1000000007;

int main() {
    int n;
    cin >> n;
    vector<int>A(n);
    for (int i=0; i<n; i++){
        cin >> A[i];
    }
    int ans=0; 
    int x=0;
    for (int i=0; i<n; i++){
        ans=(ans+(long long)x*A[i])%mod;
        x=(x+A[i])%mod;
    }
    cout << ans << endl;
}