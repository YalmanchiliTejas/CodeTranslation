#include <iostream>

using namespace std;
typedef long long int ll;
const int MAX=51;
ll len[MAX]; //size of n-th bugger
ll lenP[MAX]; // putty size for n-th bugger

// putty size of d-th bugger (l)
ll p(ll d, ll l) {
    if (d==0) {
        return l>0 ? 1:0;
    }
    if (l <=1) {
        return 0;
    }
    if (l >=len[d]) {
        return lenP[d];
    }
    ll r = p(d - 1, l -1);
    if (l <= (len[d-1] + 1)) {
        return r;
    }
    return r+1+p(d-1, l- len[d-1] -2);
}

int main() {
    ll n,x;
    cin >> n >> x;
    len[0] = 1;
    lenP[0] = 1;
    for (int i=1; i< MAX; i++) {
        lenP[i] = 2*lenP[i-1] + 1;
        len[i] = 2*len[i-1] + 3;
    }
    cout << p(n, x) << endl;
    return 0;
}