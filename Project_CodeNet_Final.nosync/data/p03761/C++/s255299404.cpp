// header {{{
#include <bits/stdc++.h>
using namespace std;

// {U}{INT,LONG,LLONG}_{MAX,MIN}
#define INF         INT_MAX/3
#define LLINF       LLONG_MAX/3
#define MOD         (1000000007LL)
#define MODA(a, b)  a=((a)+(b))%MOD
#define MODP(a, b)  a=((a)*(b))%MOD
#define inc(i, l, r)   for(int i=(l);i<(r);i++)
#define dec(i, l, r)   for(int i=(r)-1;i>=(l);i--)
#define pb          push_back
#define se          second
#define fi          first
#define mset(a, b)  memset(a, b, sizeof(a))

using LL  = long long;
using G   = vector<vector<int>>;

int di[] = {0, -1, 0, 1};
int dj[] = {1, 0, -1, 0};
// }}}

int cnt_min[26];

int main() {
    cin.tie(0);ios::sync_with_stdio(false);
    int n;cin >> n;
    inc(i, 0, n){
        string s;cin >> s;
        vector<int> cnt(26, 0);
        for(auto c : s){
            cnt[c-'a']++;
            if(i == 0){
                cnt_min[c-'a'] = cnt[c-'a'];
            }
        }
        inc(i, 0, 26){
            cnt_min[i] = min(cnt_min[i], cnt[i]);
        }
    }
    inc(i, 0, 26){
        inc(j, 0, cnt_min[i]){
            cout << char(i+'a');
        }
    }
    cout << endl;
    return 0;
}
