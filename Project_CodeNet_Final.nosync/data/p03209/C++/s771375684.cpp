#include <bits/stdc++.h>
using namespace std;

using P = pair<int,int>;
using P3 = pair<P, int>;
using ll = long long int;
constexpr int INF = 1<<30;

ll len[51], cnt[51];

ll rec(ll n, ll x){
    if(n==0){
        return x > 0;
    }else if(x == 0){
        return 0;
    }else{
        x--;
        if(x <= len[n-1]){
            return rec(n-1, x);
        }else{
            x -= len[n-1]+1;
            return rec(n-1, x) + cnt[n-1] + 1;
        }
    }
}

int main() {
    ll n, x;
    cin >> n >> x;
    len[0] = 1;
    cnt[0] = 1;
    for(int i=1;i<=50;i++){
        len[i] = len[i-1]*2+3;
        cnt[i] = cnt[i-1]*2+1;
    }
    cout << rec(n, x) << endl;
    return 0;
}
