#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> s(N);
    for(int i=0; i<N; ++i) cin >> s[i];

    long long res = 0;
    for(int c=1; c<N; ++c) {
        if((N - 1) % c) {
            long long cur = 0, tmpres = 0;
            for(int i=0, j=N-1; i<N-1 && j > c; i+=c, j-=c) {
                cur += s[i] + s[j];
                tmpres = max(tmpres, cur);
            }
            res = max(res, tmpres);
        } else {
            long long cur = 0, tmpres = 0;
            for(int i=0, j=N-1; i < j; i+=c, j-=c) {
                cur += s[i] + s[j];
                tmpres = max(tmpres, cur);
            }
            res = max(res, tmpres);
        }
    }
    cout << res << endl;
}