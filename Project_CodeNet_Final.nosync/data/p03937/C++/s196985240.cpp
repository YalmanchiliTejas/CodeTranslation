#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
#include <vector>

#define Flash ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
#define F first
#define S second
#define pb push_back
#define nl '\n'
#define NL cout << '\n';
#define EX exit(0)
#define all(s) s.begin(), s.end()
#define sz size()
#define mp make_pair
#define y1 asdf
#define rc(x) return cout << x, 0

const long long MXN = 2e3 + 1;
const long long MNN = 1e5 + 1;
const long long MOD = 1e9 + 7;
const int INF = 1e9 + 5;
const long long OO = 1e9 + 500;

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m, cnt, dp[10][10];
char t[10][10];

int main() {
    cin >> n >> m;
    int a = 0, b = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin >> t[i][j];
            if(t[i][j] == '#'){
                cnt ++;
            }
        }
    }
    if(cnt > n + m - 1 || cnt < n + m - 1 || t[1][1] != '#' || t[n][m] != '#') return cout << "Impossible", 0;
    for(int i = 1; i <= n;){
        for(int j = 1; j <= m;){
            if(t[i][j + 1] == '#'){
                j ++;
                continue;
            }
            if(t[i + 1][j] == '#'){
                i ++;
                continue;
            }
            if(i == n && j == m) return cout << "Possible", 0;
            return cout << "Impossible", 0;
        }
    }
    EX;
}
