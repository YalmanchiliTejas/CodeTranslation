/*input
10
1000 193 256 777 0 1 1192 1234567891011 48 425
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 500
#define INF 0x3f3f3f3f

int n , x[MAX];
int solve(){
    int big = 0;
    REP(i , 1 , n + 1) big = max(big , x[i]);
    if(big < n) return 0;
    REP(i , 1 , n + 1) if(x[i] == big){
        REP(j , 1 , n + 1) x[j] ++;
        x[i] += -1 - n;
        return 1;
    }
}
int32_t main(){
    IOS;
    cin >> n;
    int ans = 0;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(times , 0 , 3000000 / n / n){

        REP(i , 1 , n + 1) if(x[i] >= n) {
            int tmp = x[i] / n;
            x[i] %= n;
            ans += tmp;
            // if(tmp >= n) ans += (tmp - (n - 1)) * n , tmp = n - 1;
            REP(j , 1 , n + 1) if(i != j) x[j] += tmp;
        }
    // REP(i , 1 , n + 1) cout << x[i] << " " ; cout << endl;
    // DBGG("now ans = " , ans);
        
    }
    while(solve()) ans ++;
    cout << ans << endl;
    return 0;
}