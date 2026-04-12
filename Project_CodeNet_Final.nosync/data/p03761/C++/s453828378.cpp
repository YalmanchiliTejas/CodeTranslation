#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;


int main(){
    int n;
    cin >> n;
    vector<vector<int>>cnt(26,vector<int>(n));
    rep(i, 0, n){
        string s;
        cin >> s;
        int  m = s.size();
        rep(j, 0, m){
            cnt[s[j]-'a'][i]++;
        }
    }
    string ans;
    rep(i, 0, 26){
        int cnt2 = 100;
        rep(j, 0, n){
            cnt2 = min(cnt2, cnt[i][j]);
        }
        rep(j, 0, cnt2){
            ans += (i + 'a');
        }
    }
    cout << ans << endl;
}