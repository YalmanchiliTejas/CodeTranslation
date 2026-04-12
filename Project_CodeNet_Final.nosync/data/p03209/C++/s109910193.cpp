#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
const ll MOD = 1000000007;
const int IINF = INT_MAX;
const ll LLINF = LLONG_MAX;
const int MAX_N = int(1e5 + 5);
const double EPS = 1e-8;
const int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define ALL(v) (v).begin(), (v).end()

int main() {
    ll n, x, len[55], b[55], ans=0, k;
    cin >> n >> x;

    // レベル毎のバーガーの長さとパティの数を前計算
    len[0] = 1;
    b[0] = 1;
    REP(i,n){
        len[i+1] = len[i]*2+3;
        b[i+1] = b[i]*2+1;
    }
    
    k = n;
    while(x>0){
        if(x>=len[k]){ // レベルk分食べる
            ans += b[k];
            x -= len[k];
            if(x>0){
                ans++;
                x--;
            }
        }
        else{
            k--;
            x--;
        }
    }
    cout << ans << endl;
    return 0;
}
