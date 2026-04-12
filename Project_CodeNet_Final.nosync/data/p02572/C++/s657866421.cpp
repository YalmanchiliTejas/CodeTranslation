#include <bits/stdc++.h>
using namespace std;

long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}



int main() {
    int64_t N,total=0,c=0,naname=0;
    int64_t MOD =1000000007;
    cin >> N;
    vector<int64_t>A(N);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    for(int i=0;i<N;i++){
        c+=A.at(i);

    }
    c%=MOD;
    for(int i=0;i<N;i++){
        total+=(c*A.at(i))%MOD;
        naname+=(A.at(i)*A.at(i))%MOD;
        total%=MOD;
        naname%=MOD;
    }
    total%=MOD;
    naname%=MOD;
    total=(total-naname)%MOD;
    if(total<0)
        total+=MOD;
    cout<<total * modinv(2, MOD) % MOD<<endl;
}