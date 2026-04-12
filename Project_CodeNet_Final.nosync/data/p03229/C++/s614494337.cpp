#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 100100;
int A[MAX_N], N;

ll min_to_center() 
{
    ll res = 0;
    ll left = A[0], right = A[0];
    int i = 1, j = N-1;
    while(j - i > 0) {
        res += abs(left - A[j]);
        left = A[j];
        --j;
        if(j - i <= 0) break;
        res += abs(right - A[j]);
        right = A[j];
        --j;
        if(j - i <= 0) break;
        res += abs(left - A[i]);
        left = A[i];
        ++i;
        if(j - i <= 0) break;
        res += abs(right - A[i]);
        right = A[i];
        ++i;
        if(j - i <= 0) break;
    }
    res += max(abs(left - A[i]), abs(right - A[i]));
    return res;
}

ll max_to_center() 
{
    ll res = 0;
    ll left = A[N-1], right = A[N-1];
    int i = 0, j = N-2;
    while(j - i > 0) {
        res += abs(left - A[i]);
        left = A[i];
        ++i;
        if(j - i <= 0) break;
        res += abs(right - A[i]);
        right = A[i];
        ++i;
        if(j - i <= 0) break;
        res += abs(left - A[j]);
        left = A[j];
        --j;
        if(j - i <= 0) break;
        res += abs(right - A[j]);
        right = A[j];
        --j;
        if(j - i <= 0) break;
    }
    res += max(abs(left - A[i]), abs(right - A[i]));
    return res;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);

    sort(A, A + N);
    ll res = max(max_to_center(), min_to_center());
    printf("%lld\n", res);
    return 0;
}