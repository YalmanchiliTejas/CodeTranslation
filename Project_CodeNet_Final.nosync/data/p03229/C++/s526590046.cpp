#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
using P = pair<int,int>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    sort(all(a));

    ll ans = 0;
    if (n % 2 == 0){
        rep(i, 2){
            vector<ll> b, c;
            b.push_back(a[n/2 - i]);
            c.push_back(a[n/2 - i]);
            int left = 0, right = n-1;
            while(left < n /2 - 1){
                b.push_back(a[right]);
                b.push_back(a[left]);
                c.push_back(a[left++]);
                c.push_back(a[right--]);
            }
            b.push_back(a[n/2 - 1 + i]);
            c.push_back(a[n/2 - 1 + i]);
            ll sum1 = 0, sum2 = 0;
            rep(i,n-1) {
                sum1 += abs(b[i] - b[i+1]);
                sum2 += abs(c[i] - c[i+1]);
            }
            ans = max(ans, sum1);
            ans = max(ans, sum2);
        }        
    }else{
        vector<ll> b, c;
        b.push_back(a[n/2]);
        c.push_back(a[n/2]);
        int left = 0, right = n-1;
        while(left < n /2){
            b.push_back(a[right]);
            b.push_back(a[left]);
            c.push_back(a[left++]);
            c.push_back(a[right--]);
        }
        ll sum1 = 0, sum2 = 0;
        rep(i,n-1) {
            sum1 += abs(b[i] - b[i+1]);
            sum2 += abs(c[i] - c[i+1]);
        }
        ans = max(ans, sum1);
        ans = max(ans, sum2);
    }
    cout << ans << endl;
    return 0;
}