#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vvb = vector<vb>;
const ll MOD = 1e9+7;
vi alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z'};
int main() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    vector<set<int>> g(N);
    rep(i, M) {
        int x, y;
        cin >> x >> y;
        g[x-1].insert(y-1);
        g[y-1].insert(x-1);   
    }
    vi per;
    repp(i, N)per.push_back(i);
    do {
        int now = 0;
        int sum = 1;
        set<int> visited;
        repp(i, N-1) {
            visited.insert(now);
            int next = per[now] - 1;
            if (g[now].count(next)&&!visited.count(next)) {
                now = next;
                sum++;
            }
            else break;
        }
        if (sum==N) ans++;
    } while (next_permutation(per.begin(), per.end()));
    cout << ans << endl;
}