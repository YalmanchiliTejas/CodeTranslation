#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(int i = x ; i < n ; ++i)
#define rep(i, n) for(int i = 0 ; i < n ; ++i)
#define repr(i, n) for(int i = n - 1 ; i >= 0 ; --i)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())

const int IINF = 1e9 + 10;
const long long LLINF = (long long)1e18 + 10;
const long long MOD = (long long)1e9 + 7;
const int dx4[] = {1, 0, -1, 0}, dy4[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};
const double EPS = 1e-8;

int main(){
    lint n, x;
    cin >> n >> x;
    vector<lint> layer(n + 1), patty(n + 1);
    layer[0] = 1;
    patty[0] = 1;
    REP(i, 1, n + 1){
        layer[i] = layer[i - 1] * 2LL + 3LL;
        patty[i] = patty[i - 1] * 2LL + 1LL;
    }
    lint ans = 0;
    repr(i, n + 1){
        x = min(x, layer[i]);
        if(x > layer[i] / 2LL){
            ans += patty[i] / 2LL + 1LL;
            x -= layer[i] / 2LL + 1LL;
        }else{
            --x;
        }
    }
    cout << ans << endl;
    return 0;
}