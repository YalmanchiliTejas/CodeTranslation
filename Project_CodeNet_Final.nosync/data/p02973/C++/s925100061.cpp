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
    int n, ans = 1;
    cin >> n;
    vector<int> a(n);
    rep(i, n)cin >> a[i]; 
    reverse(all(a));
    map<int, int> mp;
    mp[a[0]]++;
    REP(i, n-1){
        auto it = mp.upper_bound(a[i]);
        if(it == mp.end()){
            mp[a[i]]++;
            ans++;
        }
        else{
            mp[it->first]--;
            if(mp[it -> first] == 0)mp.erase(it -> first);
            mp[a[i]]++;
        }
    }
    cout << ans << endl;
}
