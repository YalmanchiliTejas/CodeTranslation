#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 100100;
int A[MAX_N], coefficient[MAX_N], N;

ll up_down_so_on(){
    int down = N/2;
    int up = N - down;
    ll res = 0;
    if(N%2) { // up, down, ...., down, up
        res += A[down] + A[down + 1];
        for(int i = down + 2; i < N; ++i) res += 2*A[i];
        for(int i = 0; i < down; ++i) res += -2*A[i];
    }
    else { // up, down, ..., up, down
        res += A[down] - A[down-1];
        for(int i = down + 1; i < N; ++i) res += 2*A[i];
        for(int i = 0; i < down-1; ++i) res += -2*A[i];
    }
    return res;
}

ll down_up_so_on(){
    int up = N/2;
    int down = N - up;
    ll res = 0;
    if(N%2) { // down, up, ..., up, down
        res += -A[down-1] -A[down-2];
        for(int i = down; i< N; ++i) res += 2*A[i];
        for(int i = 0; i < down-2; ++i) res += -2*A[i];
    }
    else { // down, up, ..., down, up
        res += -A[down-1] + A[down];
        for(int i = down + 1; i < N; ++i) res += 2*A[i];
        for(int i = 0; i < down-1; ++i) res += -2*A[i];
    }
    return res;
}

int main()
{

    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);

    sort(A, A + N);
    ll res = max(up_down_so_on(), down_up_so_on());
    printf("%lld\n", res);
    return 0;
}