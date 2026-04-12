/* 
    @author : srinathbalaji_99
*/

#include<bits/stdc++.h>

//------------------------MACROS START HERE----------------------------------//

#define PB push_back
#define MP make_pair
#define endl '\n'
#define MAX LLONG_MAX
#define MIN LLONG_MIN
#define rep(i, a, b, inc) for(long long i = a; i < b; i += inc)
#define REP(i, n) rep(i, 0, n, 1)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define PLL pair<long long, long long>
#define VL vector<long long>
#define VS vector<string>
#define VLL vector<PLL>
#define VVL vector<VL>
#define MPLL map<long long, long long>
#define UMPLL unordered_map<long long, long long>
#define SETL set<long long>
#define MSETL multiset<long long>
#define GCD(a, b) __gcd(a, b)
#define LCM(a, b) (a * b)/GCD(a, b)
#define ff first
#define ss second
#define pall(a) REP(i, sizeof(a)/sizeof(a[0]))cout << a[i] << " ";cout << endl;
#define pvall(v) REP(i, v.size())cout << v[i] << " ";cout << endl;
#define gall(a, n) REP(i, n)cin >> a[i];
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;

//------------------------MACROS END HERE-------------------------------------//

using namespace std;
VVL adj;
vector<bool> vis;

//------------------------FUNCTIONS START HERE--------------------------------//

void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

VL sieve(LL n){
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;

    VL primes;
    for(LL i = 2; i * i <= n; ++i){
        if(isPrime[i]){
            for(LL j = 2 * i; j <= n; j += i){
                isPrime[j] = false;
            }
        }
    }
    REP(i, isPrime.size()){
        if(isPrime[i]){
            primes.PB(i);
        }
    }
    return primes;
}

LL powerMod(LL x, LL y, LL m){
    LL res = 1;
    while(y > 0){
        if(y & 1){
            res = (res * x) % m;
        }
        y >>= 1;
        x = (x * x) % m;
    }
    return res;
}

LL modInverse(LL x, LL m){
    return powerMod(x, m - 2, m);
}

// LL findset(LL x){
//     if(x == parents[x]){
//         return x;
//     }
//     return parents[x] = findset(parents[x]);
// }

// void merge(LL x, LL y){
//     x = findset(x);
//     y = findset(y);
//     if(x == y){
//         return;
//     }
//     if(sizes[y] > sizes[x]){
//         swap(x, y);
//     }
//     parents[y] = x;
//     sizes[x] += sizes[y];
// }

void dfs(LL node){
    vis[node] = true;
    for(auto num : adj[node]){
        if(!vis[num]){
            dfs(num);
        }
    }
}

LD dist2d(LL x1, LL y1, LL x2, LL y2){
    return sqrt((LD)((x1 - x2) * (x1 - x2)) + (LD)((y1 - y2) * (y1 - y2)));
}

LD dist3d(LL x1, LL y1, LL z1, LL x2, LL y2, LL z2){
    return sqrt((LD)((x1 - x2) * (x1 - x2)) + (LD)((y1 - y2) * (y1 - y2)) + (LD)((z1 - z2) * (z1 - z2)));
}

LD slope(LL x1, LL y1, LL x2, LL y2){
    return (LD)(y2 - y1) / (LD)(x2 - x1);
}

LL dotProduct(VL a, VL b){
    LL sum = 0;
    REP(i, a.size()){
        sum += a[i] * b[i];
    }
    return sum;
}

//------------------------FUNCTIONS END HERE----------------------------------//

using namespace std;

int main()
{
    fast();

    

    LL t,n,i,j,k,x,y,c,m;
    cin >> n;
    LL a[n];
    gall(a, n);
    LL dp[n][n];
    LL endswitht;

    if(n & 1){
        endswitht = 1;
    }
    else{
        endswitht = 0;
    }
    REP(i, n){
        REP(j, n){
            dp[i][j] = 0;
            if(endswitht){
                dp[i][i] = a[i];
            }
            else{
                dp[i][i] = -a[i];
            }
        }
    }
    LL curlevel = endswitht;
    rep(len, 2, n + 1, 1){
        curlevel = 1 - curlevel;
        for(LL i = 0; i < n - (len - 1); ++i){
            if(curlevel){
                dp[i][i + len - 1] = max(a[i] + dp[i + 1][i + len - 1], a[i + len - 1] + dp[i][i + len - 2]);
            }
            else{
                dp[i][i + len - 1] = min(-a[i] + dp[i + 1][i + len - 1], -a[i + len - 1] + dp[i][i + len - 2]);
            }
        }
    }
    
    cout << dp[0][n - 1];
}