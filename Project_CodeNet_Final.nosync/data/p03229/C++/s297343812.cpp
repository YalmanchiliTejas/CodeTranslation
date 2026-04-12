#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<iostream>
#include<cstdint>
#include<cstddef>
#include<vector>
#include<algorithm>
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
usize n;
cin >> n;
vector<i64> a(n);
rep(i,n)cin >> a[i];
sort(all(a));
i64 ans = a[n - 1] - a[0];
for(i32 i = 0,j = n - 2; i + 1 < j; i++,j--)ans += a[j] - a[i];
for(i32 i = 1,j = n - 1; i + 1 < j; i++,j--)ans += a[j] - a[i];
if(n & 1) ans += max(a[n / 2 + 1] - a[n / 2], a[n / 2] - a[n / 2 - 1]);
cout << ans << endl;
}