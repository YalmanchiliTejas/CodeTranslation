#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    vector<lli> A(n);
    rep(i, n) cin >> A[i];
    vector<lli> c1(n), c2(n);
    lli a, b, p, q;
    a = 1, b = -1;
    p = 0, q = 1;
    while(p < n && q < n){
        c1[p]+=a;
        c1[q]+=b;
        c2[p]-=a;
        c2[q]-=b;
        p++;
        q++;
        swap(p, q);
    }
    sort(A.begin(), A.end());
    sort(c1.begin(), c1.end());
    sort(c2.begin(), c2.end());
    lli u, v;
    u = v = 0;
    rep(i, n) u+=A[i]*c1[i];
    rep(i, n) v+=A[i]*c2[i];
    cout << max(u, v) << endl;
    return 0;
}
