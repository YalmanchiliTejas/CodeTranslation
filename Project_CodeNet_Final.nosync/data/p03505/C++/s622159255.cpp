#include "bits/stdc++.h"
using namespace std;
const int maxn = 5050;
int main(){
    long long k, a, b;
    cin >> k >> a >> b;
    if(a >= k) cout << 1 << endl;
    else{
        long long c = - b + a;
        if(c <= 0) cout << -1 << endl;
        else cout << 1 + 2*((k - a + c - 1) / c) << endl;
    }
    return 0;
}
