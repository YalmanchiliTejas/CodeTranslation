#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<(int)(n);i++)
#define fs first
#define sc second
typedef pair<ll, ll> l_l;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
 
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

    int N; cin >> N;
    vector<int> H(N);
    rep(i,N) cin >> H[i];
    int cnt = 1;
    bool ans = true;

    rep1(i,N) {
        ans = true;
        rep(j,i + 1) if (H[j] > H[i]) ans = false;
        if (ans == true) cnt++;
    }
    cout << cnt << endl;
}