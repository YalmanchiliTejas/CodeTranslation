#include <fstream>
#include <cmath>
#include <vector>
#include <iostream>

// BE CAREFUL WITH HASH TABLE & UNORDERED MAP
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
using namespace std;

#define MOD 998244353
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define F0R(i,b) FOR(i,0,b)
#define RFO(i,a,b) for (int i = (b-1); i >= (a); i--)
#define RF0(i,b) RFO(i,0,b)
#define lli long long int
#define pii pair<int,int>
#define add(a,b) ((int) (((lli) (a) + (b))%MOD))
#define mul(a,b) ((int) (((lli) (a) * (b))%MOD))
#define PB emplace_back
#define F first
#define S second

// ifstream cin ("cinput.in");
// ofstream cout ("coutput.out");

string N;
int K;
int dp0 [100][4] = {{0}}; // not confirmed
int dp1 [100][4] = {{0}}; // confirmed

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    F0R(i,N.size()) dp1[i][0] = 1;
    dp1[0][1] = N[0]-'0'-1;
    dp0[0][1] = 1;
    F0R(i,N.size()) {
        if (i == 0) continue;
        F0R(j,K) {
            dp1[i][j+1] = dp1[i-1][j]*9 + dp1[i-1][j+1] + max(0,dp0[i-1][j]*(N[i]-'0'-1)) + dp0[i-1][j+1]*(N[i] != '0');
            if (N[i] == '0') dp0[i][j+1] = dp0[i-1][j+1];
            else dp0[i][j+1] = dp0[i-1][j];
        }
    }
    cout << dp1[N.size()-1][K] + dp0[N.size()-1][K] << '\n';
}

// Already read the editorial. Implementing
// Decisions: 10 choices