#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;

int main() {
    //ll N; cin >> N;
    //ll N,M; cin >> N >> M;
    //string S; cin >> S;
    ll H,W; cin >> H >> W;
    ll sum=0;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char c;
            cin >> c;
            if(c=='#')sum++;
        }    
    }
    if(sum==H+W-1)cout << "Possible";
    else cout << "Impossible";
    


}

/*



 */

