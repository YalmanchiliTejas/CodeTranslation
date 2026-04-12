#include<bits/stdc++.h>

using namespace std;

#define ALL(v) v.begin(), v.end()
#define PQREV(T) vector<T>, greater<T>
#define PB push_back
#define EB emplace_back
#define CIN_FAST() cin.sync_with_stdio(false), cin.tie(NULL)

#define forempty(q) while(!q.empty())
#define endl '\n'
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

typedef long long int lint;
const int INF = 1e9;
const lint INFL = 1e18;

int main(void) {
    CIN_FAST();

    int N, K;  cin >> N >> K;
    lint res = 0;

    if (K == 0) {
        cout << (lint)N * N << endl;
        return 0;
    }


    for (int b = K+1; b <= N; b ++)
        res += (lint)(b-K) * (N/b) + (lint)max(0, (N%b-K+1));

    cout << res << endl;


    return 0;
}
