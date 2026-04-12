#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <list>
#include <cmath>
#include <stack>

using namespace std;
typedef long long ll;
using Pll = pair<ll,ll>;

vector<ll> sum(55),P(55);

ll solve(ll N,ll X){
    if(N==0){
        return (X<=0 ? 0 : 1);
    }
    else if(X<=1+sum[N-1]){
        return solve(N-1,X-1);
    }
    else{
        return P[N-1]+1+solve(N-1,X-2-sum[N-1]);
    }
}

int main() {
    ll N,X;
    cin >> N >> X;
    sum[0]=1;P[0]=1;
    for(int i=1;i<=N;i++){
        sum[i]=sum[i-1]*2+3;
        P[i]=P[i-1]*2+1;
    }
    ll ans = solve(N,X);
    cout << ans << endl;

    return 0;
}