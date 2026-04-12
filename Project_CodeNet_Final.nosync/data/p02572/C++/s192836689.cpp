#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n; cin >> n;
    long long mod = 1e9+7;
    vector<long long>a(n,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<long long>ps(n-1,0);
    ps[n-2] = a[n-1];
    for(int i = n-2; i > 0; i--){
        ps[i-1] = (ps[i] + a[i])%mod;
    }
    long long sm = 0;
    for(int i = 0; i < n-1; i++){
        long long prod = (a[i]*ps[i])%mod;
        sm = (sm + prod)%mod;
        // for(int j = i+1; j < n; j++){
        //     long long prod = (a[i]*a[j])%mod;
        //     sm = (sm + prod)%mod;
        // }
    }
    cout << sm << endl;
    return 0;
}
