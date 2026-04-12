//
// Created by maze on 2019/09/15.
//

#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int64)1e9
#define lp(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a); i < (b); i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int32_t;
using int64 = int64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

int main(void) {
    int s,t;
    cin>>s>>t;
    int p,q,m;
    cin>>p>>q>>m;
    int y;
    cin>>y;
    cout<<(s^t^y)<<endl;
}
