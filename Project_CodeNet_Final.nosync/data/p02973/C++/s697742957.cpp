#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define bit(n) (1<<(n))
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;


int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int N; cin >> N;
vi a(N); rep(i,N) cin >> a[i];

vi c;
c.push_back(a[0]);

rrep(i,N-1) {
    int key = a[i];
    int l = -1; // 常に満たさない
    int r = SZ(c); // 常に満たす
    while(r - l > 1) {
        int mid = (l + r) / 2;
        if(c[mid] < key) r = mid;
        else l = mid;
    }
    if(r == SZ(c)) c.push_back(key);
    else c[r] = key;
}
cout << SZ(c) << endl;
return 0;
}