#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define INF 1<<30
#define LINF 1LL<<60

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);
    int L; cin >> L;
    string s,t;cin >> s >> t;
    if(t + s < s + t) swap(s,t);
    string ans;
    for(int i = L; i >= 0; i--){
        ll len = s.length() * i;
        if(L - len >= 0 && (L - len)%t.length() == 0){
            for(int j = 0; j < i;j++){
                ans += s;
            }
            for(int j = 0; j < (L-len)/t.length();j++){
                ans += t;
            }
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
