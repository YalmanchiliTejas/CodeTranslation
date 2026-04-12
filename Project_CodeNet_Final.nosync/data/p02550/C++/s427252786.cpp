#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N, X, M;
    cin >> N >> X >> M;
    vector<int>ord(M, -1);
    vector<int64_t>rereki, syu;
    int64_t res = 0;
    for (int n=0; n<N; n++) {
        if (ord[X] != -1) {
            int p = ord[X];
            for (int64_t i=p; i<n; i++) {
                syu.push_back(rereki[i]);
            }
            break;
        }

        ord[X] = n;
        rereki.push_back(X);
        res += X;
        X = (X * X) % M;
    }

    N -= rereki.size();
    if (N == 0) {
        cout << res << endl;
    } else {
        vector<int64_t>sum(syu.size() + 1, 0);
        for (int i=0; i<syu.size(); i++) {
            sum[i+1] = sum[i] + syu[i];
        }

        int64_t q = N / syu.size();
        int64_t r = N % syu.size();
        res += sum[syu.size()] * q + sum[r];
        cout << res << endl;
    }
    return 0;
}