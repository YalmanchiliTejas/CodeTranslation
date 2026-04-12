#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
typedef vector<int> vec;
typedef vector<int64> vec64;
#define ss cout << " ";
#define nn cout << "\n";
#define ct(x) cout << x;
#define cts(x) cout << x << " ";
#define ctn(x) cout << x << "\n";
#define db(x) cout << "> " << #x << ": " << x << "\n";
#define qr queries();
void solve();
void YN(bool b){if (b){ctn("YES");}else{ctn ("NO");}};
void yn(bool b){if (b){ctn("Yes");}else{ctn ("No");}};
void queries(){int n;cin >> n;while (n--)solve();}
// // // // // // // // // // // // // // // // // // // // // // 
/*                  TEMPLATE - VANILLA                         */
// // // // // // // // // // // // // // // // // // // // // //
const int maxn = 200200;
const int MOD = int(1e9) + 7;
 
void solve(){

    return;
}
 
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vec64 arr (n + 1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    vec64 p (n + 1, 0);
    for (int i = 1; i <= n; i++){
        p[i] = (arr[i] + p[i-1]) % MOD;
    }
    vec64 d (n+1, 0);
    for (int i = 1; i < n; i++){
        d[i] = p[n] - p[i];
    }
    int64 rs = 0;
    for (int i = 1; i < n; i++){
        // db(arr[i]);
        rs = (rs + (arr[i] * ((d[i] + MOD) % MOD))) %MOD;
    }
    ctn(rs);
    return 0;
}
