#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<cstdint>
#include<cstddef>
#include<string>
#include<cstdlib>
#include<vector>
using namespace std;
using i32 = int_fast32_t;
using i64 = int_fast64_t;
using usize = uint_fast64_t;
#define rep(i, n) for (usize i = 0; i < (usize)(n); i++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using P = pair<i64,i64>;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    i64 n, x, m;
    cin >> n >> x >> m;

    vector<vector<i64>> doubling(64, vector<i64>(m,-1));
    vector<vector<i64>> sum(64,vector<i64>(m,0));
    rep(i,m){
        doubling[0][i] = i * i % m;
        sum[0][i] = i;
    }
    rep(i,63){
        rep(j,m){
            doubling[i + 1][j] = doubling[i][doubling[i][j]];
            sum[i + 1][j] = sum[i][j] + sum[i][doubling[i][j]];
        }
    }
    i64 ans = 0;
    i64 now = x;
    for(i64 i = 63; i >= 0; i--){
        if(n & ((i64)(1) << i)){
            ans += sum[i][now];
            now = doubling[i][now];
        }
    }
    cout << ans << endl;
}