#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)

bool is_small(vector<long long>& a){
    int N = a.size();
    REP(i, N){
        if(a[i] >= N) return false;
    }
    return true;
}


int main()
{
    int N;
    cin >> N;
    vector<long long> a(N);
    REP(i, N) cin >> a[i];

    long long ans = 0;
    while(!is_small(a)){
        long long S = 0;
        REP(i, N) S += a[i]/N;
        REP(i, N) a[i] = a[i] - (a[i]/N)*N + (S-a[i]/N);
        ans += S;
    }
    cout << ans << endl;

    return 0;
}