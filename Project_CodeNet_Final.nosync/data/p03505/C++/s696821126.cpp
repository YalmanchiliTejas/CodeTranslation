#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define pll pair<ll,ll>
#define rep(i,n) for(int i=0;i<n;i++) 
const ll INF = 1LL<<60;
const ll mod = (int)1e9 + 7;

int main() {
    //ll N; cin >> N;
    //ll N,M; cin >> N >> M;
    //string S; cin >> S;
    //ll H,W; cin >> H >> W;
    ll K,A,B;
    cin >> K >> A >> B;
    if(K<=A)cout << 1;
    else if(A<=B)cout << -1;
    else{
        cout << (K-A-1)/(A-B)*2+3;
    }
    


}

/*



 */

