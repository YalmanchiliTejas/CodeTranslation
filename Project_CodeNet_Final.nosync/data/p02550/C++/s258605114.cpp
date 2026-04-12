#include <bits/stdc++.h>
using namespace std;

#define rep(i,x,y) for(ll i=(x);i<(y);i++)
#define rrep(i,x,y) for(ll i=(ll)(y)-1;i>=(x);i--)
#define all(x) (x).begin(),(x).end()
#define itrout(x) for(int i=0;i<x.size();i++) {cout << x[i] << (i==x.size()-1 ? "\n" : " ");}
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define debugbit(x, n) cerr << #x << " = " << bitset<n>(x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl
#define itrdebug(x) cerr << #x << " "; for (auto & el : (x)) {cerr << (el) << " ";} cerr << endl
#define dassert(...) assert(__VA_ARGS__)
#else
#define debug(x)
#define debugbit(x, n)
#define itrdebug(x)
#define dassert(...)
#endif
//#define int long long

typedef long long ll;
const ll MOD = 1e9 + 7;
const long double EPS = 1e-8;

void solve(long long N, long long X, long long M){
    ll answer = 0;
    ll loopSum = 0, loopCnt = 0;
    ll i = 1, current = X;
    vector<int> lastIndex(M+1, 0);
    vector<ll> sum(M+1);
    while (true) {
        loopSum += current;
        if (i == N) {
            cout << loopSum << endl;
            return;
        }
        if (lastIndex[current] != 0) {
            loopCnt = i - lastIndex[current];
            answer += loopSum - current;
            loopSum = loopSum - sum[current];
            N -= i-1;
            answer += (N / loopCnt) * loopSum;
            N %= loopCnt;
            break;
        }
        sum[current] = loopSum;
        lastIndex[current] = i;
        current = (current*current) % M;
        i++;
    }
    ll s = 0;
    i=0;
    rep(i,0,N) {
        s += current;
        ll next = (current*current) % M;
        current = next;
    }
    answer += s;
    cout << answer << endl;
}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    long long N;
    scanf("%lld",&N);
    long long X;
    scanf("%lld",&X);
    long long M;
    scanf("%lld",&M);
    solve(N, X, M);
    return 0;
}
