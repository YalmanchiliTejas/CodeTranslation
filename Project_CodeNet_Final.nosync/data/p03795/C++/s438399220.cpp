#include <bits/stdc++.h>
using namespace std;
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define IDX(vec, element_iter) distance((vec).begin(), element_iter)
#define pb push_back
#define mp make_pair
#define INF9 1000000000 //10^9
#define MOD 1000000007 //10^9+7
#define fi first
#define sc second
using ll=long long;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vstr=vector<string>;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout<<fixed<<setprecision(20);

    int n; cin >> n;
    int ans = 800*n - 200*(n/15);
    cout << ans << endl;
    return 0;
}