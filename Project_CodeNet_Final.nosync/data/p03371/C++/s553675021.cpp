#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#define Cin(T, x) T x; cin >> x
#define Cins(T, n, xs) vector<T> xs(n); For(i, n) cin >> xs[i]
#define Cins2(T, n, xs, ys) vector<T> xs(n), ys(n); For(i, n) cin >> xs[i] >> ys[i]
#define Cins3(T, n, xs, ys, zs) vector<T> xs(n), ys(n), zs(n); For(i, n) cin >> xs[i] >> ys[i] >> zs[i]
#define Cout(x) cout << (x) << "\n"
#define Couts(xs) for(const auto &e : xs) cout << e << " "; cout << "\n"
#define Cusum(T, n, xs, sxs) vector<T> sxs(n+1); For(i, n) sxs[i+1] = sxs[i] + xs[i]
#define For(i, n) for(int i = 0; i < (n); i ++)
#define Range(c) c.begin(), c.end()
#define RevRange(c) c.rbegin(), c.rend()
#define Contains(c, x) find(Range(c), x) != c.end()
#define Sort(a) sort(Range(a))
#define DeSort(a) sort(RevRange(a))
#define Vec2(T, vs, n, m) vector<vector<T>> vs(n, vector<T>(m))
#define Sum(a) accumulate(Range(a), 0)

using namespace std;
using ll = long long;

int main(void){
    Cin(int, a);
    Cin(int, b);
    Cin(int, c);
    Cin(int, x);
    Cin(int, y);
    
    if(a+b <= 2*c){
        Cout(a*x + b*y);
        return 0;
    }
    int z = abs(x-y), d = ((x > y) ? a : b);
    int ans = min(x, y)*2*c + min(d, 2*c)*z;
    Cout(ans);
}
