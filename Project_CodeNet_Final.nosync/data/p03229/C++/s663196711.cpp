#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <cstdlib>
using namespace std;
using ll = long long int;

int main()
{
    int N;
    cin >> N;

    ll A[N];
    for (int i = 0; i < N; i++) {cin >> A[i];}

    sort(A,A+N);

    ll small = 0;
    ll big = 0;
    if (N % 2 == 0) {
        for (int i = 0; i < N/2; i++) small += A[i];
        small *= 2;
        small -= A[N/2 - 1];
        for (int i = N/2; i < N; i++) big += A[i];
        big *= 2;
        big -= A[N/2];

        cout << big - small << endl;
    }
    else {
        for (int i = 0; i < N/2; i++) small += A[i];
        small *= 2;
        for (int i = N/2; i < N; i++) big += A[i];
        big *= 2;
        big -= A[N/2]+A[N/2+1];
        ll ans1 = big - small;

        small = 0;
        big = 0;
        for (int i = 0; i <= N/2; i++) small += A[i];
        small *= 2;
        small -= A[N/2 - 1] + A[N/2];
        for (int i = N/2+1; i < N; i++) big += A[i];
        big *= 2;
        ll ans2 = big - small;

        cout << max(ans1,ans2) << endl;
    }
}
