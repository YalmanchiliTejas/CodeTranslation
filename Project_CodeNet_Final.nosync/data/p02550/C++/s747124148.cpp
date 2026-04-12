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
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    LL N, X, M;
    cin >> N >> X >> M;

    vector<LL> A;
    vector<int> Indexes(M, -1);

    int index = 0;
    LL val = X;
    LL total = 0;
    while(Indexes[val] == -1){
        A.push_back(val);
        Indexes[val] = index;
        index++;
        total += val;
        val = (val*val)%M;
    }

    LL cycleSum = 0;
    int cycle = index - Indexes[val];
    for(int i=Indexes[val]; i<index; i++){
        cycleSum += A[i];
    }

    LL ans = 0;
    if(N <= index){
        REP(i, N){
            ans += A[i];
        }
        cout << ans << endl;
        return 0;
    }

    ans += total;
    N -= index;

    LL r = N % (cycle);
    LL q = N / (cycle);

    ans += (cycleSum * q);

    for(int i=Indexes[val]; i<Indexes[val]+r; i++){
        ans += A[i];
    }

    cout << ans << endl;
    
    return 0;
}