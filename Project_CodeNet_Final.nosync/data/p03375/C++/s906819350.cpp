#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define int long long
using namespace std;

typedef pair<int, int> Pii;

template<typename T>
void readvec(vector<T> &a);
void readindex(vector<int> &a);

int calcmod(int x, int M){
    if(x >= 0) return x % M;
    int n = -1 * (x / M) + 1;
    return (x + n * M) % M; 
}

int extgcd(int a, int b, int &x, int &y){
    int d = a;
    if(b != 0){
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }else{
        x = 1;
        y = 0;
    }
    return d;
}

int mod_inverse(int a, int m){
    int x, y;
    extgcd(a, m, x, y);
    return (m + x % m) % m;
}

signed main(){

    int N, M;
    cin >> N >> M;

    vector< vector<int> > dp(N + 1, vector<int>(N + 1, 0));
    FOR(i, 0, N + 1){
        dp[i][0] = 1;
    }
    FOR(j, 1, N + 1){
        dp[0][j] = 0;
    }
    FOR(i, 1, N + 1){
        FOR(j, 1, N + 1){
            dp[i][j] = (dp[i - 1][j - 1] + (j + 1) * dp[i - 1][j]) % M;
        }
    }

    //2^(i*j)
    vector< vector<int> > pow1(N + 1, vector<int>(N + 1, 1));
    FOR(i, 1, N + 1){
        pow1[i][1] = (2 * pow1[i - 1][1]) % M;
    }
    FOR(i, 1, N + 1){
        FOR(j, 2, N + 1){
            pow1[i][j] = (pow1[i][j - 1] * pow1[i][1]) % M;
        }
    }

    //2^(2^i)
    vector<int> pow2(N + 1, 1);
    REP(i, N + 1){
        //2^(M-1)=1(mod M)
        //2^i mod(M-1)を知りたい
        int t = 1;
        for(int j = 50; j >= 0; j--){
            t = (t * t) % (M - 1);
            if(((i >> j) & 1) == 1){
                t = (t * 2) % (M - 1);
            }
        }
        //2^t mod Mを求める
        for(int j = 50; j >= 0; j--){
            pow2[i] = (pow2[i] * pow2[i]) % M;
            if(((t >> j) & 1) == 1){
                pow2[i] = (pow2[i] * 2) % M;
            }
        }
    }

    vector<int> ways(N + 1);
    vector< vector<int> > ways2(N + 1, vector<int>(N + 1));

    FOR(i, 0, N + 1){
        ways[i] = 0;
        FOR(j, 0, i + 1){
            ways2[i][j] = dp[i][j];
            //j杯に他のトッピング載せる？(*2^(j*(N-i)))
            ways2[i][j] = (ways2[i][j] * pow1[j][N - i]) % M;

            //残りのN-i種類のトッピングのみで作る2^(N-i)種類のそれぞれ食べる?(*2^(2^(N-i)))
            ways2[i][j] = (ways2[i][j] * pow2[N - i]) % M;

            ways[i] = (ways[i] + ways2[i][j]) % M;
        }
    }

    vector<int> fact(N + 1, 1);
    FOR(i, 1, N + 1){
        fact[i] = (fact[i - 1] * i) % M;
    }
    
    int ans = 0;
    REP(i, N + 1){
        int tmp = (fact[N] * mod_inverse(fact[i], M)) % M;
        tmp = (tmp * mod_inverse(fact[N - i], M)) % M;
        if(i % 2 == 0){
            tmp = calcmod(tmp, M);
        }else{
            tmp = calcmod(-1 * tmp, M);
        }
        tmp = tmp * ways[i];
        ans = (ans + tmp) % M;
    }

    cout << ans;
    return 0;
}


template<typename T>
void readvec(vector<T> &a){
    REP(i, a.size()){
        cin >> a[i];
    }
}
void readindex(vector<int> &a){
    REP(i, a.size()){
        cin >> a[i];
        a[i]--;
    }
}