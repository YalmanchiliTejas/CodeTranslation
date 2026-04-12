#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define mset(a, b) memset(a, b, sizeof a)
#define rep(i, a, b) for(int i(a), i##_END_(b); i <= i##_END_; i++) 
#define drep(i, a, b) for(int i(a), i##_END_(b); i >= i##_END_; i--)
using namespace std;
template<class T> inline bool tomax(T &a, T b) {return a < b ? a = b, 1 : 0;}
template<class T> inline bool tomin(T &a, T b) {return b < a ? a = b, 1 : 0;}
typedef long long ll;
typedef double db;

const int N = 1e5 + 5;

int a[N], b[N];

int main() {
    int n;
    scanf("%d", &n);
    rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
    int tot = 0;
    b[++tot] = a[1];
    rep(i, 2, n) {
        if(b[tot] >= a[i]) b[++tot] = a[i];
        else {
            int l = 1, r = tot, mid, o;
            while(l <= r) {
                mid = (l + r >> 1);
                if(b[mid] < a[i]) r = mid - 1, o = mid;
                else l = mid + 1;
            }
            b[o] = a[i];
        }
    }
    printf("%d\n", tot);
    return 0;
}
