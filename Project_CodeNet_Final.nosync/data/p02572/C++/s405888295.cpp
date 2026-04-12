#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    const int q = 1000000007;
    cin >> n;
    vector<long long> a(n,0); 
    vector<long long> b(n,0); 
    long long s=0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        s = (s+a[i])%q;
        if (i==0) b[i] = a[i];
        else      b[i] = (a[i] + b[i-1])%q;
    }
    long long sum = (s*s)%q;
    // cout << sum << endl;
    for (int i=0; i<n; i++) {
        long long ab = (a[i]*b[i])%q;
        // cout << a[i] <<"*" << b[i] << "="<<ab << endl;
        sum = (sum - ab)%q;
        if (sum<0) sum += q; 
    }
    // cout << -4/3 <<"," <<-4%3<< endl;
    // long long sum = 0;
    // for (int i=0; i<n-1; i++) {
    //     // cout << s << "-" << b[i]<< "="<< (s - b[i])%q<< endl;
    //     sum=(sum+(a[i]*(s - b[i])%q)%q)%q;
    // }
    cout << sum << endl;
    return 0;
}