#include <iostream>
#include <cstring>

using namespace std;

#define N 10100
#define MAX_D 128
#define M 1000000007LL

inline long long MOD (long long x){
    if (x < M)
        return x;
    return x - M;
}
string s;
long long d[N][MAX_D][2];
int n, D, i, j, c, C;

int main (){
    cin >> s >> D;
    n = s.size();

    d[0][0][0] = 1;
    ++n;
    for (i = 1; i < n; ++i){
        C = s[i - 1] - '0';
        for (j = 0; j < D; ++j){
            for (c = 0; c < 10; ++c)
                d[i][(j + c) % D][1] = MOD(d[i][(j + c) % D][1] + d[i - 1][j][1]);

            for (c = 0; c < C; ++c)
                d[i][(j + c) % D][1] = MOD (d[i][(j + c) % D][1] + d[i - 1][j][0]);

            d[i][(j + C) % D][0] = MOD (d[i][(j + C) % D][0] + d[i - 1][j][0]);
        }
    }
    --n;
    cout << MOD (d[n][0][0] + d[n][0][1] + M - 1);

    return 0;
}
