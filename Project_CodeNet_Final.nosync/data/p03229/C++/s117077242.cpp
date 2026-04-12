#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
    ll N,r=0;
    cin >> N;
    vector<ll> A(N),t(N);
    rep(i,N)
        cin >> A.at(i);
    sort(A.begin(), A.end());

    if(N%2) {
        ll r1=0,r2=0;
        rep(i,N/2)
            t.at((i+1)*2) = A.at(i);
        t.at(0) = A.at(N/2);
        rep(i,N/2)
            t.at(i*2+1) = A.at(i+N/2+1);
        rep(i,N-1)
            r1 += abs(t.at(i)-t.at(i+1));
        
        rep(i,N/2)
            t.at(i*2) = A.at(i+N/2+1);
        t.at(N-1) = A.at(N/2);
        rep(i,N/2)
            t.at(i*2+1) = A.at(i);
        rep(i,N-1)
            r2 += abs(t.at(i)-t.at(i+1));

        r = max(r1,r2);
    } else {
        rep(i,N/2)
            t.at(i*2) = A.at(i+N/2);
        rep(i,N/2)
            t.at(i*2+1) = A.at(i);
        rep(i,N-1)
            r += abs(t.at(i)-t.at(i+1));
    }

    cout << r << endl;
}