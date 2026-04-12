#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); ++i)
#define FOR(i, s, n) for(int i=(int)(s); i<(int)(n); ++i)
#define ALL(n) (n).begin(), (n).end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> mat;

const ll MAX_V = 100000;
const ll INF = 1e9;
const ll MOD = 998244353;

int main(){
    int N; cin >> N;
    vi H(N); REP(i, N) cin >> H[i];
    int cnt = 0;
    int maxh = 0;
    REP(i, N){
        if (maxh <= H[i]){
            cnt++;
            maxh = H[i];
        }
    }
    cout << cnt << endl;
}