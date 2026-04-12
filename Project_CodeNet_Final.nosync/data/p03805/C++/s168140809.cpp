#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INCANT cin.tie(0), ios::sync_with_stdio(false), cout << fixed << setprecision(20)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define out(a) cout << a << endl
#define PRINT(V) for (auto v : (V)) cout << v << " "

const int MOD = 1000000007;
const double PI = acos(-1.0);

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> a(N, vector<int>(N,0));
    rep(i, M) {
        int ai, bi;
        cin >> ai >> bi;
        a[ai-1][bi-1] = 1;
        a[bi-1][ai-1] = 1;
    }
    vector<int> node;
    FOR(i, 1, N) node.push_back(i);
    int ans=0;
    do{
        int prev=0;
        int flag=1;
        for(auto &x : node){
            if(!a[prev][x]){
                flag=0;
                break;
            }
            prev=x;
        }
        if(flag) ans++;
    }while(next_permutation(all(node)));
    out(ans);
}
int main() {
    INCANT;
    solve();
    return 0;
}


