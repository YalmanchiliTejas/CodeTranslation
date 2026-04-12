#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i = (a); i < (b); ++i)
#define REP(i, n) for(ll i = 0; i < (n); ++i)
#define ARRAY_LENGTH(array) sizeof(array)/sizeof(*array)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

int main() {
    ll N, M;
    cin >> N >> M;

    vector<int> sides[N + 1];
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        sides[a].push_back(b);
        sides[b].push_back(a);
    }

    vector<int> one_case;
    for(int i = 2; i <= N; ++i) {
        one_case.emplace_back(i);
    }

    int wayCnt = 0;
    do {
        bool canGoThrough = true;
        int nx_num = 0;
        int cr = 1, nx = one_case[nx_num];

        do { 
            bool canMove = false;

            for(int j = 0; j < (int)sides[cr].size(); ++j) {
                if(sides[cr][j] == nx) {
                    canMove = true;
                }
            }

            if(!canMove) {
                canGoThrough = false;
            }

            ++nx_num;
            if(nx_num < one_case.size()) {
                cr = nx, nx = one_case[nx_num];
            } 
        } while(nx_num < one_case.size() && canGoThrough);

        if(canGoThrough) {
            ++wayCnt;
        }
    } while(next_permutation(one_case.begin(), one_case.end()));

    cout << wayCnt << endl;

    return 0;
}