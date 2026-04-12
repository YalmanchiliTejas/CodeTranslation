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
    vector<int> s(N);
    REP(i,N){
        cin >> s[i];
    }

    ll ans = 0;
    FOR(i,1,N){
        if((N-1)%i == 0){
            ll tmp_ans = 0;
            ll current = 0;

            int l = 0;
            int r = N-1;
            while(l<r){
                current += s[l] + s[r];
                tmp_ans = max(tmp_ans, current);
                l += i;
                r -= i;
            }
            ans = max(ans, tmp_ans);
        }else{
            ll tmp_ans = 0;
            ll current = 0;

            int l = 0;
            int r = N-1;
            while(l<N-1 && r>i){
                current += s[l] + s[r];
                tmp_ans = max(tmp_ans, current);
                l += i;
                r -= i;
            }
            ans = max(ans, tmp_ans);
        }
    }

    cout << ans << endl;

    return 0;
}