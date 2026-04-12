#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int N;
    cin >> N;
    vector<LL> A(N);
    LL q = 1000000000 + 7;
    REP(i, N){
        LL val;
        cin >> A[i];
    }

    LL sum =0;
    REP(i,N){
        sum+=A[i];
    }

    LL ans = 0;
    LL tmp =0;
    REP(i,N){
        tmp += A[i];
        ans += ((A[i]%q)*((sum - tmp)%q))%q;
    }

    ans = ans % q;
    cout << ans << endl;
    return 0;
    
}