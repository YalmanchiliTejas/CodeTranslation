
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int N;
int A[3010];
ll dp[3010][3010];

ll rec(int from, int to){
    if(dp[from][to] >= 0) return dp[from][to];
    ll res = 0;
    if(from > to){
        res = 0;
    }
    else{
        bool is_taro = (N - (to - from + 1)) % 2 == 0;
        if(is_taro){
            res = max(res, rec(from + 1, to) + A[from]);
            res = max(res, rec(from, to - 1) + A[to]);
        }
        else{
            res = rec(from + 1, to);
            res = min(res, rec(from, to - 1));
        }
    }
    return dp[from][to] = res;
}

int main(){

    cin >> N;
    
    ll tot = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        tot += A[i];
    }
    memset(dp, -1, sizeof(dp));
    ll s = rec(0, N - 1);
    cout << s - (tot - s) << endl;

    return 0;
}
