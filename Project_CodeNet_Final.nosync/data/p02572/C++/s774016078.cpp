#include <bits/stdc++.h>

using namespace std;

int main(void) {
    long mod = 1000000007;
    int n;
    int ans = 0;
    cin >> n;
    vector<long> a(n);
    vector<long> add(n);
    // long addtmp = 0;
    for(int i = 0; i < n; i++){
        cin >> a.at(i);
    }
    add.at(n - 1) = a.at(n - 1);
    // cout << n - 1 << " " << add.at(n - 1) << endl;
    for(int i = n - 2; i >=0 ; i--){
        add.at(i) = ((long)(add.at(i + 1) + a.at(i))) % mod;
        // cout << "add  i = " << i << " " << add.at(i) << endl;
    }
    for(int i = 0; i < n - 1; i++){
        long mul = (long)(a.at(i) * add.at(i + 1));
        int tmp = mul % mod;
        ans = ((long)(ans + tmp)) % mod;
        // cout << "ans = " << ans << endl;
        // for(int j = i + 1; j < n; j++){
        //     long mul = (long)(a.at(i) * a.at(j));
        //     int tmp = mul % mod;
        //     ans = ((long)(ans + tmp)) % mod;
        // }
    }
    cout << ans << endl;
    return 0;
}