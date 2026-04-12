#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
#define REPi(i, a, b) for(int i=int(a); i<int(b); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int N;
ll A[3100];
ll memo[3100][3100];

ll func(ll x, ll y, ll remain){
    if(remain == 0){
        return 0;
    }

    if(memo[x][y] >= 0){
        return memo[x][y];
    }

    ll xi = x;
    ll yi = N-1-y;

    ll ret = 0;
    ll left = remain - func(x+1, y, remain-A[xi]);
    ll right = remain - func(x, y+1, remain-A[yi]);
    ret = max(left, right);
    return memo[x][y] = ret;
}

int main(){
    cin >> N;
    ll sum = 0;
    REP(i,N){
        ll a;
        cin >> a;
        A[i] = a;
        sum += a;
    }

    REP(i,N){
        REP(j,N){
            memo[i][j] = -1;
            memo[i][j] = -1;
        }
    }

    ll X = func(0, 0, sum);

    //printf("\n");
    //REP(i,N){
    //    REP(j,N){
    //        if(memo[i][j] == -1) continue;
    //        printf("%lld ", memo[i][j]);
    //    }
    //    printf("\n");
    //}

    ll Y = sum - X;
    ll ans = X - Y;
    cout << ans << endl;
    return 0;
}
