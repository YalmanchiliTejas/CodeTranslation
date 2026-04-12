#include <iostream>
#include <vector>

using namespace std;


int main(void) {
    int64_t N, X, M;
    cin >> N >> X >> M;

    vector<int64_t> v(M), v2(M);
    while(!v[X] && N) {
        --N;
        v[X] = 1;
        X = X*X % M;
    }

    if(N <= 0) {
        int64_t ans = 0;
        for(int64_t j=0; j<M; j++) {
            ans += j * v[j];
        }
        cout << ans << endl;
        return 0;
    }

    int64_t cnt = 0;
    while(!v2[X] && N) {
        --N;
        ++cnt;
        v2[X] = 1;
        X = X*X % M;
    }

    if(N <= 0) {
        int64_t ans = 0;
        for(int64_t j=0; j<M; j++) {
            ans += j * (v[j] + v2[j]);
        }
        cout << ans << endl;
        return 0;
    }

    int64_t tmp = N/cnt;
    for(auto &e: v2) {
        e *= (tmp + 1);
    }

    N %= cnt;
    while(N) {
        --N;
        v2[X] ++;
        X = X*X % M;
    }

    int64_t ans = 0;
    for(int64_t j=0; j<M; j++) {
        ans += j * v[j];
        ans += j * v2[j];
    }

    cout << ans << endl;
    return 0;
}
