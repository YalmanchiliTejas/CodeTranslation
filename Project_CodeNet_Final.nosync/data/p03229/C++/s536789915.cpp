#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <tuple>
#include <deque>
#include <numeric>
#include <bitset>
#include <iomanip>
#include <cassert>
#include <chrono>
#include <random>
#include <limits>
#include <iterator>
#include <functional>
#include <sstream>
#include <complex>
using namespace std;

typedef long long ll;
typedef uint64_t ull;
typedef pair<int, int> P;
typedef pair<int, double> Pid;
typedef pair<double, int> Pdi;
typedef pair<ll, int> Pl;
typedef pair<ll, ll> Pll;
typedef pair<int, pair<int, int>> PP;
typedef pair<P, int> PPi;
constexpr double PI = 3.1415926535897932;   // acos(-1)
constexpr double EPS = 1e-9;
constexpr int INF = 1001001001;
constexpr int mod = 1000000007;
// constexpr int mod = 998244353;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define chadd(x, y) x = (x + y) % mod

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)  cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    int foo = a[0], bar = a[0];
    int cnt = 1;
    bool flag = true;
    ll sum = 0;
    int left = 1, right = n - 2;
    while(cnt < n){
        if(n - cnt >= 2){
            if(flag){
                sum += a[right] + a[right + 1] - foo - bar;
                foo = a[right];
                bar = a[right + 1];
                right -= 2;
                flag = false;
            }
            else{
                sum += foo + bar - a[left] - a[left + 1];
                foo = a[left];
                bar = a[left + 1];
                left += 2;
                flag = true;
            }
            cnt += 2;
        }
        else{
            if(flag)    sum += max(a[right] - foo, a[right] - bar);
            else    sum += max(foo - a[left], bar - a[left]);
            ++cnt;
        }
    }
    chmax(ans, sum);
    foo = a[n - 1], bar = a[n - 1];
    left = 0, right = n - 3;
    cnt = 1;
    flag = true;
    sum = 0;
    while(cnt < n){
        if(n - cnt >= 2){
            if(flag){
                sum += foo + bar - a[left] - a[left + 1];
                foo = a[left];
                bar = a[left + 1];
                left += 2;
                flag = false;
            }
            else{
                sum += a[right] + a[right + 1] - foo - bar;
                foo = a[right];
                bar = a[right + 1];
                right -= 2;
                flag = true;
            }
            cnt += 2;
        }
        else{
            if(flag)    sum += max(foo - a[left], bar - a[left]);
            else    sum += max(a[right] - foo, a[right] - bar);
            ++cnt;
        }
    }
    chmax(ans, sum);
    cout << ans << endl;
}