#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
//#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122
#define int long long

/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/


using namespace std;

int F (string a, string b){
    int pas = 0;
    int n = (int)a.size(), m = (int)b.size();
    for (int i = 0; i < min (n, m); i++){
        if (a[i] != b[i])
            break;
        pas++;
    }
    return pas;
}

const int N = 3005, MOD = 998244353;

int n, S;
int a[N];
int dp[N];
int ans;

main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> S;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        for (int j = S - a[i]; j >= 0; j--){
            dp[j + a[i]] += dp[j];
            dp[j + a[i]] %= MOD;
        }
        dp[a[i]] += i;
        ans += dp[S];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}
