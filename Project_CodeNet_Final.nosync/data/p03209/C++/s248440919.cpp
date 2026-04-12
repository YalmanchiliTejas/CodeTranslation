#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007LL;
long long GCD(long long a, long long b){return b == 0 ? a : GCD(b, a % b);}

long long completed[52][2];

pair<long long, long long> precomp(long long n){

    if(n == 1LL){
        return make_pair(3LL, 2LL);
    }

    pair<long long, long long> state = precomp(n - 1LL);

    completed[n - 1][0] = state.first;
    completed[n - 1][1] = state.second;

    return make_pair(state.first * 2LL + 1LL, state.second * 2LL + 2LL);

}

long long helper(long long n, long long x){

    if(n == 1){
        if(x < 1)
            return 0LL;
        return x - 1LL - (x >= 5LL ? 1LL : 0LL);
    }

    long long half = completed[n - 1][0] + completed[n - 1][1] + 2LL;

    if(x >= half * 2LL - 3LL){
        return completed[n][0];
    } else if(x >= half){
        return completed[n - 1][0] + 1LL + helper(n - 1LL, x - half);
    } else {
        return helper(n - 1LL, x - 1LL);
    }

}

int main(){

    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    long long n, x;
    cin >> n >> x;

    pair<long long, long long > state = precomp(n);
    completed[n][0] = state.first;
    completed[n][1] = state.second;

    cout << helper(n, x);

    return 0;
}
