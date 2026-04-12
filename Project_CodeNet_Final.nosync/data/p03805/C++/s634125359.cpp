#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define MOD 1000000007
#define IINF (INT_MAX/2)
#define LLINF (LLONG_MAX/2)

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

int main() {
    int N, M; cin >> N >> M;
    vvi ab(N);
    rep(i,M) {
        int a,b;
        cin >> a >> b;
        a--; b--;
        ab[a].emplace_back(b);
        ab[b].emplace_back(a);
    }
    vi ch(N);
    rep(i,N) ch[i] = i;

    int ans = 0;

    do{
        bool flag = true;
        rep(i, N-1) {
            auto itr = find(ab[ch[i]].begin(), ab[ch[i]].end(), ch[i+1]);
            if(itr == ab[ch[i]].end()) {
                flag = false;
                break;
            }
        }
        if(flag) ans++;
    }while(next_permutation(ch.begin(), ch.end()) && ch[0] == 0);

    cout << ans << "\n";
    return 0;
}
