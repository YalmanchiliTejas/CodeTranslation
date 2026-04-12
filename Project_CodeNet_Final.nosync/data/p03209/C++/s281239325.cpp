#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


ll rec(int N, ll X){
    if(N==0) return 1;
    ll len = (1LL<<(N+1)) - 3;//N-1の最大長
    ll num = (1LL<<N) - 1;//N-1のパティ数

    if(X==1) return 0;
    else if(X<=len+1) return rec(N-1, X-1);
    else if(X==len+2) return num + 1;
    else if(X<=2*len + 2) return num + 1 + rec(N-1, X-len-2);
    else return num*2 + 1;
}

int main() {
    int N; ll X; cin >> N >> X;

    cout << rec(N,X) << endl;

    return 0;
}