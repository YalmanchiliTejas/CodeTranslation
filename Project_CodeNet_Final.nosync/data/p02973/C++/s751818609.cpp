#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    vector<int> C;
    rep(i, N){
        int a; cin >> a;
        int x = upper_bound(C.begin(), C.end(), -a) - C.begin();
        if(x == C.size()){
            C.push_back(-a);
        } else {
            C[x] = -a;
        }
    }

    int ans = C.size();
    cout << ans << endl;

    return 0;
}