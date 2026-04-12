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
    vector<int> as(n);
    rep(i, n) cin>>as[i];

    int q;
    cin>>q;
    rep(i, q) {
        int k;
        cin>>k;
        cout<<distance(as.begin(), lower_bound(as.begin(), as.end(), k))<<endl;
    }
}
