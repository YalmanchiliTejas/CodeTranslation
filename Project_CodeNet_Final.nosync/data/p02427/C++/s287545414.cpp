#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;

    rep(i, 1<<n) {
        cout<<i<<":"<<(i != 0 ? ' ' : '\n');
        int temp = i;
        vector<int> res;
        rep(j, n) {
            if (temp & 1) res.push_back(j);
            temp = temp >> 1;
        }
        rep(j, res.size()) cout<<res[j]<<(j != res.size() - 1 ? ' ' : '\n');
    }
}
