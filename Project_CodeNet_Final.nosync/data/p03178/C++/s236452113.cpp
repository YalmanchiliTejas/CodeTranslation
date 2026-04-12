/*
 * ID: adityaa
 * LANG: C++
 */
#include <bits/stdc++.h>
using namespace std;

#define fio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define mem(x, y) memset(x, y, sizeof x);
#define fi first
#define se second
#define pb push_back
#define pii pair<int , int>
#define asdfg y1
#define int long long
#define double long double
#define endl '\n'
#define PI 3.14159265359

/*-----------------------------------------------------------------------*/

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

/*-----------------------------------------------------------------------*/

// check base cases n = 0 , n = 1
// max / min questions - check for binary search
const int maxn = (int) 1e4 + 4;
const double EPS = 1e-9;
const int INF = (int)1e18 + 18;
const int mod = (int) 1e9 + 7;
string in;
vector<int> K;
int n , D , dp[maxn][100][2];

int go(int index , int modD , int tight){
    if(dp[index][modD][tight] != -1){
        return dp[index][modD][tight];
    }
    if(index == 0){
        int cnt = 0;
        int up = (tight ? K[index] : 9);
        for(int i = 0; i <= up; i++){
            if(i % D == modD) cnt++;
        }
        return dp[index][modD][tight] = cnt;
    }
    int up = (tight ? K[index] : 9);
    int ret = 0;
    for(int i = 0; i <= up; i++){
        int new_tight = tight;
        if(tight == 1 && i < up) new_tight = 0;
        ret += go(index - 1 , (modD - i + i * D) % D , new_tight);
        ret %= mod;
    }
    return dp[index][modD][tight] = ret;
}

signed main() {
    
    fio;
    cin >> in >> D;
    reverse(in.begin(), in.end());
    n = in.length();
    for(int i = 0; i < n; i++){
        int dig = in[i] - '0';
        K.push_back(dig);
    }
    
    for(int i = 0; i < n; i++){
        for(int d = 0; d < D; d++){
            for(int j = 0; j < 2; j++){
                dp[i][d][j] = -1;
            }
        }
    }
    
    int ans = go(n - 1 , 0 , 1);
    cout << (ans - 1 + mod) % mod << endl;
    
    
    
    return 0;
    
}
