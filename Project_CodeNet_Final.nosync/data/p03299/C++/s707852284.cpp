#include <bits/stdc++.h>
#define int long long
using namespace std;
int MOD = 1000000007;
int pw(int a, int b){
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b%2) return ((a * pw(a, b-1)) % MOD);
    int rs = pw(a, b/2);
    return (rs*rs) % MOD;
}
pair<int, int> solve(vector<int> &v){
    int n = v.size();
    int mn = 1e12;
    for (int i=0; i < n; i++) mn = min(mn, v[i]);
    int holes = 0;
    vector<pair<int, int> > ress;
    vector<int> a, b;
    for (int i=0; i < n; i++){
        if (v[i] > mn) a.push_back(v[i] - mn);
        else{
            if (a.size() > 0){
                ress.push_back(solve(a));
                b.push_back(a.size());
            }
            a.clear();
            holes++;
        }
    }
    if (a.size() > 0){
        ress.push_back(solve(a));
        b.push_back(a.size());
    }
    int N = 2;
    for (int i=0; i < ress.size(); i++) {
        //cout << ress[i].first << " " << ress[i].second << endl;
        N *= ress[i].second;
        N %= MOD;
    }
    N %= MOD;
    int on = N;
    N *= pw(2, mn-1);
    N %= MOD;
    int R = pw(2, holes);
    for (int i=0; i < ress.size(); i++){
        int H = (ress[i].first + 2 * ress[i].second) % MOD;
        R *= H;
        R %= MOD;
    }
    R -= on;
    R %= MOD;
    if (R < 0) R += MOD;
    return {R, N};
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++){
        cin >> v[i];
    }
    pair<int, int> p = solve(v);
    //cout << p.first << " " << p.second << endl;
    cout << (p.first + p.second) % MOD << endl;
    return 0;
}
