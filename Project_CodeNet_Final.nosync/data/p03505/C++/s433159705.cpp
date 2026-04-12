#include<bits/stdc++.h>
using namespace std;

int main(){

    long long k, a, b; cin >> k >> a >> b;
    if(k <= a) cout << 1 << endl;
    else if(a <= b) cout << -1 << endl;
    else{
        long long n = (k - a) / (a - b) + 2;
        if((k - a) % (a - b) == 0) n--;
        cout << 2*n - 1 << endl;
    }
    return 0;
}