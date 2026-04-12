#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<int> a(n), ra(n), ans1(n), ans2(n);
    rep(i, n)cin >> a[i];
    sort(all(a));
    ra = a;
    reverse(all(ra));
    vector<P> x, y;
    rep(i, n){
        if(i % 2 == 0){
            if(i == 0 || i == n-1)x.push_back(make_pair(1, i));
            else x.push_back(make_pair(2, i));
        }
        else{
            if(i == 0 || i == n-1)y.push_back(make_pair(1, i));
            else y.push_back(make_pair(2, i));
        }
    }
    sort(rall(x)); sort(rall(y));
    rep(i, x.size()){
        ans1[x[i].second] = a[i];
        ans2[x[i].second] = ra[i];
    }
    rep(i, y.size()){
        ans1[y[i].second] = ra[i];
        ans2[y[i].second] = a[i];
    }
    ll c = 0, d = 0;
    rep(i, n-1){
        c += abs(ans1[i] - ans1[i+1]);
        d += abs(ans2[i] - ans2[i+1]);
    }
    cout << max(c, d) << endl;
}
