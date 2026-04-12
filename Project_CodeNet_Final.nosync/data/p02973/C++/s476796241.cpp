#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int dx[] = { 0, 1, -1, 0, 1, -1, 1, -1 };  // i<4:4way i<8:8way
int dy[] = { 1, 0, 0, -1, 1, -1, -1, 1 };

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0):n(n),d(n+1) {}
    void add(int i,T x=1){
        for(i++;i<=n;i += i&-i){
            d[i] += x;
        }
    }
    T sum(int i){
        T x = 0;
        for(i++;i;i-= i&-i) {
            x += d[i];
        }
        return x;
    }
    // 下の2個の操作を使う時は上の2個の操作が使えない事に注意
    T getmax(int i){ // get max(d[i]) for i = 0,1,...,i-1,i
        T x = 0;
        for(i++;i;i-=i&-i) {
            x = max(x, d[i]);
        }
        return x;
    }
    void setmax(int i, int v){ // set d[i] = max(d[i], v)
        for(i++;i<=n;i+=i&-i){
            d[i] = max(d[i], v);
        }
    }
};

int a[100005];
vector<int> dp(1e5+5,1e9+7);

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,ans = 0;
    cin >> n;
    rep(i,n)cin >> a[i];
    for(int i=n-1;i>=0;i--){
        *upper_bound(ALL(dp),a[i]) = a[i];
    }
    cout << lower_bound(ALL(dp),1e9+7) - dp.begin() << endl;
}