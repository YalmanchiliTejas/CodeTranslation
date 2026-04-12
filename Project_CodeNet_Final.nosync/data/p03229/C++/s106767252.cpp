#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef long long int lli;
typedef pair<int, int> ii;

int main() {
    int N;
    cin >> N;
    int A[100009];
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    sort(A, A + N);

    //patternA
    lli a = 0;
    lli b = 0;
    if (N % 2 == 1) {
        for (int i = 0; i < N/2; i++) {
            a -= A[i] * 2;
        }
        a += A[N/2] + A[N/2 + 1];
        for (int i = N/2 + 2; i < N; i++) {
            a += A[i] * 2;
        }

        for (int i = 0; i < N/2 - 1; i++) {
            b -= A[i] * 2;
        }
        b -= (A[N/2 - 1] + A[N/2]);
        for (int i = N/2 + 1; i < N; i++) {
            b += A[i] * 2;
        }
    } else {
        for (int i = N/2 + 1; i < N; i++) {
            a += A[i] * 2;
        }
        a += A[N/2];
        a -= A[N/2 - 1];
        for (int i = 0; i < N/2 - 1; i++) {
            a -= A[i] * 2;
        }

        for (int i = 0; i < N/2 - 1; i++) {
            b -= A[i] * 2;
        }
        b -=  A[N/2 -1];
        b += A[N/2];
        for (int i = N/2 + 1; i < N; i++) {
            b += A[i] * 2;
        }
    }
    cout << (a > b ? a : b) << endl;
}
