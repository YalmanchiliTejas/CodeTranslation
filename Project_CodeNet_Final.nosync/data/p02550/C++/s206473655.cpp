/**
 *   @FileName	e.cpp
 *   @Author	kanpurin
 *   @Created	2020.09.19 21:36:51
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    ll n,x,m;cin >> n >> x >> m;
    vector<ll> a;
    a.push_back(x);
    vector<int> b(m,-1);
    vector<ll> sum(m+1,0);
    int start,end; 
    sum[0] = x;
    for (int i = 0; i <= m; i++) {
        a.push_back(a[i] * a[i] % m);
        sum[i+1] = sum[i] + a[i+1];
        if (b[a[i+1]] != -1) {
            start = b[a[i+1]];
            end = i+1;
            break;
        }
        b[a[i+1]] = i+1;
    }
    if (n-1 <= end) {
        cout << sum[n-1] << endl;
        return 0;
    }
    ll k = sum[end] - sum[start];
    ll t = (n-1-end);
    
    cout << sum[end] + t/(end-start)*k+sum[t%(end-start)+start]-sum[start] << endl;
    return 0;
}