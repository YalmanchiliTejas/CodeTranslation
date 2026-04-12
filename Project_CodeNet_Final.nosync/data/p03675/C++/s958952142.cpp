#include <bits/stdc++.h>

using namespace std;
int input(){
    int res = 0; char c = ' ';
    while (c < '0') c = getchar();
    while (c >= '0') res = res * 10 + (c - '0'), c = getchar();
    return res;
}
const int N = 2e5 + 1;

int b[N << 1];
int main(){
    int n = input(), start = N, l = N, r = N - 1;
    for (int i = 0; i < n; ++ i){
        if (i & 1)
            b[-- l] = input();
        else
            b[++ r] = input();
    }
    if (n & 1)
        for (int i = r; i >= l; -- i)
            cout << b[i] << " ";
    else
        for (int i = l; i <= r; ++ i)
            cout << b[i] << " ";
}
