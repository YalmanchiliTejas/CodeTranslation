#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<cstdint>
#include<cstddef>
using namespace std;
using i32 = int_fast32_t;
using i64 = int_fast64_t;
using usize = uint_fast64_t;
#define rep(i, n) for (usize i = 0; i < (usize)(n); i++)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
using P = pair<i64,i64>;

int main(){
ios::sync_with_stdio(false);
std::cin.tie(nullptr);

i64 n,m;
cin >> n >> m;
cout << (n == m ? "Yes" : "No") << endl;
}