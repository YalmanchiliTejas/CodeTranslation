#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int N;
ll X;
ll len[51];
ll pan[51];

ll l(int n){
    if(n == 0) return len[n] = 1;
    return len[n] = l(n - 1) * 2 + 3;
}

ll p(int n){
    if(n == 0) return pan[n] = 1;
    return pan[n] = p(n - 1) * 2 + 1;
}

ll rec(int n, ll x){
    if(n == 0){
        return 1;
    }
    if(x == 1){
        return 0;
    }else if(x <= 1 + len[n - 1]){
        return rec(n - 1, x - 1);
    }else if(x == 1 + len[n - 1] + 1){
        return pan[n - 1] + 1;
    }else{
        return pan[n - 1] + 1 + rec(n - 1, x - (1 + len[n - 1] + 1));
    }
}

signed main(){
    cin >> N >> X;
    l(50);
    p(50);
    cout << rec(N, X) << endl;
}