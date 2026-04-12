#include<bits/stdc++.h>

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define eb emplace_back

using i32 = int;
using i64 = long long;

using namespace std;

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);

    i64 n;cin >> n;
    vector<i64> s(n);
    REP(i,n)cin >> s[i];

    i64 ans = 0;
    for(i64 C = 1;C < n - 1;C++){
        map<i64,i32> used;
        i64 tmp = 0;
        for(i64 k = 0;(k+1) * C < n-1;k++){
           if(used[(n-1)-k*C]++ || used[k*C]++)break;
           tmp += s[(n-1) - k*C] + s[k*C];
           ans = max(ans , tmp);
        }
    }
    cout << ans << '\n';
}

