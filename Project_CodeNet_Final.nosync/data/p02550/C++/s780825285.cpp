#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=998244353;
const LL LINF=1ll<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};



int main(){
    LL n,x,m;cin >> n >> x >> m;
    if(n <= 1000000){
        LL ans = 0;
        LL a = x;
        for (int i = 0; i < n; i++) {
            ans += a;
            a = a * a % m;
        }
        cout << ans << endl;
    }
    else{
        vector<LL> a(1000001);
        a[0] = x;
        for (int i = 0; i < 1000000; i++) {
            a[i+1] = a[i] * a[i] % m;
        }
        vector<int> s(1000000, -1);
        LL l, r;
        for (int i = 0; i < 1000000; i++) {
            if(s[a[i]] != -1){
                l = s[a[i]];
                r = i;
                break;
            }
            else s[a[i]] = i;
        }
        LL ans = 0;
        for (int i = 0; i < l; i++) {
            ans += a[i];
        }
        LL rs = 0;
        for (int i = l; i < r; i++) {
            rs += a[i];
        }
        n -= l;
        LL t = r - l;
        LL q = n / t;
        ans += q * rs;
        n -= q * t;
        for (int i = 0; i < n; i++) {
            ans += a[l + i];
        }
        cout << ans << endl;
    }
    return 0;
}
