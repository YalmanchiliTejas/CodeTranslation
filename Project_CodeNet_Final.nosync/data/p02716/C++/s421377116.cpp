#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iomanip>
using namespace std;
#define SORT(A) std::sort(A.begin(), A.end())
#define RSORT(A) std::sort(A.begin(), A.end(), std::greater<>())
#define FR(A, e) for (auto& e : A)
#define SHOW(A) for (auto& e : A) {cout << e << " ";}; cout << endl;
#define within(x,_left,_right) (_left <= x && x <= _right)
#define ALL(A) A.begin(),A.end()
#define pb push_back
#define sz(x) ((int)x.size())
#define fi first
#define se second
using LL = long long;
using db = double;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VL = vector<LL>;
using VVL = vector<VL>;
const LL MOD = 1e9 + 7;
typedef std::pair<int, int> PII;
typedef std::pair<LL, LL> PLL;
typedef std::pair<int, char> PIC;
using std::cin;
using std::vector;
using std::cout;
using std::endl;
// int dx[4] = {1, -1, 0, 0}; // 冯诺依曼型邻居
// int dy[4] = {0, 0, 1, -1};
// int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // 摩尔型邻居
// int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// 字符串类:模拟规律 -> Greedy -> dp -> kmp || Automation (注意数据量， 先数学后暴力)
// #include<iomanip> cout << fixed <<  setprecision(k) 输出k位精度
const int N = 2e5 + 5;
LL a[N], even_mx[N / 2];
LL se[N], so[N];
LL MIN = -1e16;
LL get_even(int gt){
    if (even_mx[gt] != 0) return even_mx[gt];
    if (gt == 0) return MIN;
    if (gt == 1) return even_mx[1] = max(a[1], a[2]);
    else return even_mx[gt] = max(get_even(gt - 1) + a[2*gt], so[gt]);
}

LL helper(int len, int gt){
    if (gt == 0) return 0;
    if (len % 2 == 0) return get_even(gt);
    else {
        return max(get_even(gt), helper(len - 2, gt - 1) + a[len]);
    }
}

int main(){
    int n = 0, k = 0;
    cin >> n;
    // memset(even_mx, 0x80, sizeof(even_mx));
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 1; i <= n; ++ i){
        if (i & 1) so[(i + 1) / 2] += (so[(i - 1) / 2] + a[i]);
        else se[i / 2] += (se[i / 2 - 1] + a[i]);
    }
    LL ans = helper(n, floor(n >> 1));
    cout << ans << endl;
    return 0;
}
