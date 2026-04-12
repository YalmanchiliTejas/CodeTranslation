//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int n;
ll x;
ll dfs(ll xx, int nn) {
    if(nn == 1) {
        int h = 0;
        switch(xx) {
            case 4:
            case 5:
            ++h;
            case 3:
            ++h;
            case 2:
            ++h;
        }
        return h;
    }

    ll c = (1LL<<(nn+2))-3;
    
    if(c == xx) {
        return (1LL<<nn+1)-1;
    }
    if(xx == 1) {
        return 0;
    }
    if(c/2 >xx) {
        return dfs(xx-1, nn-1);
    } else if(c/2 == xx) {
        return dfs(xx-1, nn-1);
    } else if(xx == c/2+1) {
        return 1LL<<n;
    } else {
        xx -= c/2+1;
        return dfs(xx, nn-1) + (1LL<<nn);
    }
}


int main() {
    cin >> n >> x;
    cout << dfs(x, n) << endl;
}