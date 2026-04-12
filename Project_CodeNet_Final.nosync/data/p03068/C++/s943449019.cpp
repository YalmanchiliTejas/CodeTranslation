#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;

int main() {
    ll N; cin >> N;
    //ll N,M; cin >> N >> M;
    string S; cin >> S;
    //ll H,W; cin >> H >> W;
    int K;
    cin >> K;
    for(int i=0;i<N;i++){
        if(S[i]!=S[K-1])S[i]='*';
    }
    cout << S;
    


}

/*



 */

