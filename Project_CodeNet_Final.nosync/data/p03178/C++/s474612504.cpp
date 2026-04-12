#include<bits/stdc++.h>
using namespace std;

#define y1 hasjdnasd
#define ii pair < int , int >
#define iii pair < int , ii >
#define iv pair < ii , ii >

#define fi first
#define se second
#define pb push_back
#define fr front()

#define FOR(i , x , n) for(int i = x ; i <= n ; ++i)
#define FORD(i , x , n) for(int i = x ; i >= n ; --i)
#define REP(i , x) for(int i = 0 ; i < x ; ++i)

#define ll long long
#define oo 1e18 + 7
#define int long long

const int N = 1e4 + 5;
const int VAL = 1e2 + 5;
int n , k , mod = 1e9 + 7;
int dp[N][VAL];
int a[N];
char f[N];

int add(int a , int b , int mod)
{
    return (a + b) % mod;
}

int sub(int a , int b , int mod)
{
    return ((a - b) % mod + mod) % mod;
}

void init()
{
    FOR(i , 0 , 9)
        dp[1][i % k] += 1;
    FOR(i , 2 , n)
        FOR(j , 0 , k)
            FOR(x , 0 , 9)
                dp[i][j] = add(dp[i][j] , dp[i - 1][sub(j , x , k)] , mod);
}

int getdigit(int idx , int tight , int sum , int r)
{
    int ans = 0;
    int lim = (tight == 1) ? a[idx] : 9;
    FOR(i , 0 , lim)
    {
        int x = (tight & (i == a[idx]));
        int y = add(i , sum , k);
        if(idx == r && i == 0 && idx != 1)
            continue;
        if(idx == 1)
            ans += (y % k == 0);
        else
        {
            if(x == 1)
                ans = add(ans , getdigit(idx - 1 , x , y , r) , mod);
            else
                ans = add(ans , dp[idx - 1][sub(k , y , k)] , mod);
        }
    }
    return ans;
}

main()
{
    //freopen("S.inp","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> f;
    n = strlen(f);
    FORD(i , n , 1)
        a[i] = f[i - 1] - 48;
    reverse(a + 1 , a + 1 + n);
    cin >> k;
    init();
    cout << sub(add(getdigit(n , 1 , 0 , n) , dp[n - 1][0] , mod) , 1 , mod);
}
