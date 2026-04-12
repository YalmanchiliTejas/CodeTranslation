#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define int long long
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e18;

signed main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, k;
    string s;
    cin >> n >> s >> k;
    k--;
    rep(i, 0, n){
        if(s[i] != s[k]) s[i] = '*';
    }
    cout << s << endl;
}
