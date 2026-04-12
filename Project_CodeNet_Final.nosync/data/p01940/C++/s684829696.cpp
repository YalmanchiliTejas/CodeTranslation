#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define REP(i, n) rep(i, 0, n)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define int long long
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef pair<int, int> P;
const int mod = 1000000007;
const int INF = 1e12;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string t, p;
    cin >> t >> p;
    vector<int> a, b;
    int now = 0;
    bool f = true;
    rep(i, 0, t.size()){
        if(t[i] == p[now] && now < p.size()){
            a.push_back(i);
            now++;
        }
    }
    if(now != p.size()) f = false;
    now = p.size() - 1;
    repb(i, t.size() - 1, 0){
        if(t[i] == p[now] && now >= 0){
            b.push_back(i);
            now--;
        }
    }
    reverse(all(b));
    if(f && a == b){
        cout << "yes" << endl;
    }else{
        cout << "no" << endl;
    }
}