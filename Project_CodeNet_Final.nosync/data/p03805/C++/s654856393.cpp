#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <numeric>
#include <cmath>

#define rep(i, n) for(int i = 0;i < (int)(n); i++)
#define pb push_back
typedef long long ll;

using namespace std;

int main() {
    int p[10];
    int n,m;
    cin >> n >> m;
    bool ok[n][n];
    rep(i, n) rep(j ,n) ok[i][j] = false;
    rep(i, m){
        int a, b;
        cin >> a >> b;
        ok[a-1][b-1] = true;
        ok[b-1][a-1] = true;
    }

    rep(i, n) p[i] = i;
    int count = 0;
    do {
        int flg = true;
        for(int j = 1; j < n; j++){
            if(!ok[p[j - 1]][p[j]]) {
                flg = false;
                break;
            }
        }
        if(flg) count++;
    } while (next_permutation(p + 1, p + n));
    //next?permutationは最後だったらfalse返すので
    //全部のPの順列に大してこれで処理できる.

    cout << count << endl;

    return 0;
}
