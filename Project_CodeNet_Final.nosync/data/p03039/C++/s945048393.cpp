#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <map>
#include <stack>
#include <iomanip>
#include <set>
#include <sstream>
#include <cmath>
#include <deque>
#include <list>
#include <bitset>
using namespace  std;
typedef pair<long long , long long> P;
typedef long long ll;
typedef long long lint;
#define REP(i, n) for(long long (i)=0; (i)<(n); ++i)
#define FOR(i, a, b) for(long long (i)=(a); (i)<(b); ++i)
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define FST first
#define SND second
const lint MOD = (lint) 1e9 + 7;
lint pow(lint n, lint x) {
    lint res = 1LL;
    while(x){
        if(x%2==1) res = (res*n) % MOD;
        x = x>>1;
        n= (n*n) % MOD;
    }
    return res%MOD;
}
lint factorial(lint n) {
    if(n<=1) return 1;
    else return (n * factorial(n-1))%MOD;
}
 
lint cmb(lint n, lint r){
    lint res = 1LL;
    r = min(r, n-r);
    for(lint i=n-r+1; i<=n; i++) res = (res*i)%MOD;
    res *= pow(factorial(r), MOD-2);
    return res % MOD;
}
signed main(){
    lint N, M, K; cin >> N>>M>>K;
    lint res = 0;
    lint a = cmb(N*M-2, K-2);
    for(int dx=0; dx<M; dx++){
        for(int dy=0; dy<N; dy++){
            if(dx==0 and dy==0) continue;
            lint cnt;
            if(dx==0 or dy==0) cnt = (M-dx)*(N-dy);
            else cnt = (M-dx)*(N-dy)*2;
            cnt = (cnt*a) %MOD;
            res = (res + cnt*(dx+dy)%MOD) %MOD; 
        }
    }
    cout << res % MOD << endl;
    return 0; 
}