#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i, n) FOR(i,0,n)
#define WARI 1000000007  

int main(void){
    ll N;
    unsigned long long ans=0,sum = 0,now=0;
    cin >> N;
    vector<unsigned long long> A(N+10);
    REP(i,N){
        cin >> A[i];
    }
    vector<unsigned long long>Now(N+10);
    Now[0]=0;
    FOR(i,1,N) Now[i] = Now[i-1] + A[i-1];
    FOR(i,0,N){
        ans += (Now[i] % WARI)* A[i];
        ans %= WARI;
    }
    cout << ans << endl;
    return 0;
}