#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<n;++i)
#define SORT(name) sort(name.begin(), name.end())
#define ZERO(p) memset(p, 0, sizeof(p))
#define MINUS(p) memset(p, 1, sizeof(p))

#define INF 1000000000

ll N;
list<ll> A;
int main()
{
    cin >> N;
    REP(i, N) {
        ll a;
        cin >> a;
        if(i % 2 == 0) {
            A.push_back(a);
        } else {
            A.push_front(a);
        }
    }
    if(N % 2 != 0) {
        auto it = A.end();
        it--;
        for(int i = N - 1; i >= 0; --i) {
            printf("%lld", *it);
            if(i != 0) { printf(" "); }
            it--;
        }
    } else {
        auto it = A.begin();
        REP(i, N) {
            printf("%lld", *it);
            if(i != N - 1) { printf(" "); }
            it++;
        }
    }
    printf("\n");

    return 0;
}
