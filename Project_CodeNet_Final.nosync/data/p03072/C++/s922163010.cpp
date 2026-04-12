#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define ALL(obj) (obj).begin(), (obj).end()
#define INF 1e9
typedef long long ll;


int main() {
    int N;
    cin >> N;
    vector<int> H(N);
    REP(i,N){
        cin >> H[i];
    }

    int ans = 0;
    REP(i,N){
        bool ok = true;
        REP(j,i){
            if(H[i] < H[j]){
                ok = false;
            }
        }
        if(ok){
            ans ++;
        }
    }
    cout << ans << endl;
    return 0;
}