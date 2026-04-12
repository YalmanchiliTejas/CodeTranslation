#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
const int MAXN = 1e5+1;
const int MOD = 1e9+7;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second 
#define debug(x)  do{cerr<<#x<<": "<<x<<"\n";}while(0)
#define debugv(x) do{cerr<<#x<<": ";for(auto&e: (x))cerr<<e<<" ";cerr<<"\n";}while(0)
#define FAIL0 {cout << "0\n"; return 0;}
#define FAIL1 {cout << "-1\n"; return 0;}
#define FAILNO {cout << "No\n"; return 0;}
#define YES {cout << "Yes\n"; return 0;}

int N;
multiset<int> S;

int main() {
#ifdef OJ
    freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        if (S.size()) {
            auto it = S.lower_bound(a);
            if (it != S.begin()) {
                --it;
                S.erase(it);
            }
        }
        S.insert(a);
    }

    cout << S.size() << endl;
    return 0;
}
