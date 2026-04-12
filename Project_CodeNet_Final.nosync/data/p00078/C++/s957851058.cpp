#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <complex>

using namespace std;
typedef long long ll;
#define loop(i,a,b) for(ll i=(a); i<ll(b); i++)
#define rep(i,b) loop(i,0,b)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef complex<double> P;

int main(){
    int n;
    while (cin >> n && n){
        vvi g(n, vi(n));
        int x = n / 2, y = n / 2 + 1;
        loop(i, 1, n*n + 1){
            // cout << x << " " << y << endl;
            g[y][x] = i;
            x = (x + 1) % n, y = (y + 1) % n;
            if (g[y][x]) x = (x - 1 + n) % n, y = (y + 1) % n;
        }
        rep(i, n)rep(j, n){
            printf("%4d", g[i][j]);
            if (j + 1 == n) puts("");
        }
    }
}