#include<bits/stdc++.h>

using namespace std;

#define endl "\n"
#define lln long long unsigned int
#define IOS ios::sync_with_stdio(0);cin.tie(0);

const lln MOD = 1e9 + 7;

int main(){
    IOS;

    int n;
    cin >> n;
    vector<lln> a(n);
    vector<lln> sum(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
        if(i==0) sum[i] = a[i];
        else sum[i] = (a[i] + sum[i-1]) % MOD;
    }
    sum[n-1] += MOD;
    lln ans = 0;
    for(int i=0;i<n-1;i++){
        lln val = (a[i] * (sum[n-1] - sum[i])) % MOD; 
        ans = (ans + val) % MOD;
    }
    cout << ans << endl;
    return 0;    
}