#include "bits/stdc++.h"
using namespace std;
#define FOR(i,j,k) for(int (i)=(j);(i)<(int)(k);++(i))
#define rep(i,j) FOR(i,0,j)
#define each(x,y) for(auto &(x):(y))
#define mp make_pair
#define mt make_tuple
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<(x)<<endl
#define smax(x,y) (x)=max((x),(y))
#define smin(x,y) (x)=min((x),(y))
#define MEM(x,y) memset((x),(y),sizeof (x))
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, Q;
    cin >> N >> Q;
    vi cup(N), mag(N);
    cup[0] = 1;
    int ball = 0;
    for (int i = 0; i <= Q; ++i) {
        for (int j = max(0, ball - 1); j < min(N, ball + 2); ++j) {
            mag[j] |= 1;
        }
        if (i == Q)break;
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (cup[a] || cup[b]) {
            ball = cup[a] ? b : a;
        }
        swap(cup[a], cup[b]);
        swap(mag[a], mag[b]);
    }
    int ans = accumulate(all(mag), 0);
    cout << ans << endl;
}
