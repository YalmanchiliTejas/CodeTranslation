#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
const int MOD = 1000000007;
 
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

int main(){
    int n, k; cin >> n>> k;
    ll ans = 0;
    FOR(i,k+1, n+1){
        ans += n/i * (i-k);
        if(n %i!=0){
            ans += max(0, n%i-k+1);
            if(k==0){
                ans--;
            }
        }
    
    }
    cout << ans << endl;

}