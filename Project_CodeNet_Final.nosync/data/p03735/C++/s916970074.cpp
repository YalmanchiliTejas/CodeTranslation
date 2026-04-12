#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> B;

int main() {
    scanf("%d", &N);
    B.resize(N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &B[i].first, &B[i].second);
        if(B[i].first > B[i].second) swap(B[i].first, B[i].second);
    }
    int rmn = 1e9, rmx = 0;
    int bmn = 1e9, bmx = 0;
    for(int i = 0; i < N; i++) {
        rmn = min(rmn, B[i].first);
        rmx = max(rmx, B[i].first);
        bmn = min(bmn, B[i].second);
        bmx = max(bmx, B[i].second);
    }
    long long ans = (long long)(rmx - rmn)*(bmx - bmn);
    sort(B.begin(), B.end());
    bmn = rmn;
    int tmn = 1e9;
    for(int i = 0; i < N; i++) {
        tmn = min(tmn, B[i].second);
        rmn = tmn;
        if(i != N - 1) rmn = min(rmn, B[i + 1].first);
        rmx = max(rmx, B[i].second);
        ans = min(ans, (long long)(bmx - bmn)*(rmx - rmn));
    }
    printf("%lld", ans);
}
