#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// 定数宣言
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll nCr(ll n, ll r) {
    ll ans = 1;
    for (ll i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (ll i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}

ll pow(ll N, ll k) {
    ll res = 1;
    for (ll i = 0; i < k; ++i) res *= N;
    return res;
}

string N;
int K;
int L;
int A[100];

/*
rec(i, k, smaller) := i 桁目以降について、0 以外の値を残り K 個使用可能という状況を考える。
このとき i 桁目までの部分が「等しい」か「strict に小さくなっている」かを smaller フラグによって分岐する。
*/
ll solve(ll i,ll k, ll smaller) {
        if (i == L) {
            if (k == 0) return 1;
            else return 0;
        }
        if (k == 0) return 1;
        
        if (smaller) return nCr(L-i, k) * pow(9, k);
        else {
            if (A[i] == 0) return solve(i+1, k, false);
            else {
                ll zero = solve(i+1, k, true);
                ll aida = solve(i+1, k-1, true) * (A[i] - 1);
                ll icchi = solve(i+1, k-1, false);
                return zero + aida + icchi;
            }
        }
    }
int main()
{
    cin >> N;
    cin >> K;

    L = N.length();
    // 桁ごとの数字の取得
    for(int i=0; i<L; i++){
        A[i] = N[i] - '0';
    }
    cout << solve(0,K,false) << endl;
    return 0;
}