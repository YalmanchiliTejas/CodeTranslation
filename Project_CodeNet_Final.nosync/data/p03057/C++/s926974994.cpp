#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(auto &it : (v))
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;
#define sz(x) (int)(x).size()

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

bool canGo(string S, int sind, string T, int tind) {
    if (tind == sz(T))
        return true;
    if (S[sind] == T[tind]) {
        if (canGo(S, (sind+1)%sz(S), T, tind+1))
            return true;
    }
    if (S[(sind+sz(S)-1)%sz(S)] == T[tind]) {
        if (canGo(S, (sind+sz(S)-1)%sz(S), T, tind+1))
            return true;
    }
    return false;
}

ll solve(int N, int M, string S) {
    if (S[0] == 'B') {
        rep(i,0,M) {
            if (S[i] == 'R')
                S[i] = 'B';
            else
                S[i] = 'R';
        }
    }
    bool anyB = false;
    int maxRInRow = N+1;
    int rInRow = 0;
    rep(i,0,M) {
        if (S[i] == 'B') {
            if (rInRow%2) {
                maxRInRow = min(maxRInRow, rInRow);
            }
            if (!anyB && rInRow%2 == 0) {
                maxRInRow = min(maxRInRow, rInRow+1);
            }
            anyB = true;
            rInRow = 0;
        }
        else {
            ++rInRow;
        }
    }
    if (anyB) {
        if (N%2) {
            return 0;
        }
        vector<ll> dp(N+1);
        dp[0] = 1;
        ll add = 1;
        rep(i,1,N+1) {
            if (i%2)
                dp[i] = 0;
            else {
                dp[i] = add;
                add += dp[i];
                if (i > maxRInRow) {
                    add -= dp[i-maxRInRow-1];
                }
                add %= MOD;
                if (add < 0)
                    add += MOD;
            }
        }
        ll ans = 0;
        for (int i = 2; i <= maxRInRow+1 && i <= N; i += 2) {
            ans += i*dp[N-i];
        }
        ans %= MOD;
        return ans;
    }
    else {
        vector<ll> dp[2][2];
        rep(i,0,2)
        rep(j,0,2)
            dp[i][j] = vector<ll>(N+1);
        dp[0][0][0] = 1;
        dp[1][1][0] = 1;
        rep(i,1,N+1) {
            rep(j,0,2)
            rep(k,0,2) {
                dp[j][k][i] += dp[j][!k][i-1];
                if (k == 0)
                    dp[j][k][i] += dp[j][k][i-1];
                dp[j][k][i] %= MOD;
            }
        }
        ll ans = 0;
        ans += dp[0][0][N];
        ans += dp[1][1][N];
        ans %= MOD;
        return ans;
    }
}

int main(){
    /*while (true) {
        int N = (rand()%6) + 2;
        int M = (rand()%7) + 1;
        string S;
        rep(i,0,M) {
            if (rand()%2)
                S.push_back('R');
            else 
                S.push_back('B');
        }
        ll ans = 0;
        vector<string> answers;
        rep(i,0,(1<<N)) {
            string T;
            rep(j,0,N) {
                if (i&(1<<j))
                    T.push_back('R');
                else
                    T.push_back('B');
            }
            bool ok = 1;
            rep(j,0,N) {
                if (!canGo(T, j, S, 0))
                    ok = 0;
            }
            if (ok)
            answers.push_back(T);
            ans += ok;
        }
        ll guess = solve(N, M, S);
        if (ans != guess) {
            cerr << N << " " << M << " " << S << endl;
            cerr << ans << " " << guess << endl;
            for (string s : answers)
                cerr << s << endl;
            assert(0);
        }
    }*/
	ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    cout << solve(N, M, S) << endl;
}
