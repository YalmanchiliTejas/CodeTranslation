#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef pair<int, int> P;

const ll mod =  1000000007;  //出力は (ans % mod + mod) % mod  (負の剰余を正にする)
const int inf = 1e9;
const long long INF = 1LL << 60;   // INF = 1152921504606846976

int main()
{
    int a,b,c; cin >> a >> b >> c;
    int x,y; cin >> x >> y;
    int t = a * x + b * y;
    if(x < y){
        int s = x * 2 * c + (y-x) * b;
        int u = y * 2 * c;
        cout << min({s,t,u});
    }else{
        int s = y * 2 * c + (x-y) * a;
        int u = x * 2 * c;
        cout << min({s,t,u});
    }
}