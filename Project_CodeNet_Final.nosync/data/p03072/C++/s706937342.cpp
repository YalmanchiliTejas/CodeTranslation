#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const double PI = acos(-1);
const int inf = 2e9;
const ll INF = 2e18;
const ll MOD = 1e9+7;

#define sz(s) (s).size()
#define pb push_back
#define fi first
#define se second
#define REP(i,n) for (int i = 0; i<n; i++)
#define ALL(a) begin(a), end(a)

int main (void) {
    int N;
    cin>>N;
    vector<int> H(N);
    REP(i,N) cin>>H[i];
    int ans = 1;
    for (int i=1;i<N;i++) {
        bool flag = true;
        for (int j=0;j<i;j++) {
            if (H[i] < H[j]) flag = false;
        }
        if (flag) ans++;
    }
    cout<<ans<<endl;
    return 0;
}