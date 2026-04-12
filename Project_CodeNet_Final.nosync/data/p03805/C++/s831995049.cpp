#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {

    int N, M; cin >> N >> M;
    vector<vector<int> > vec(N+2, vector<int>(N+2, 0));
    rep(i, M) {
        int x, y; cin >> x >> y;
        vec[x][y] = 1; vec[y][x] = 1;
    }

    vector<int> order(N-1);
    rep (i, N-1) order[i] = i + 2;

    int sum = 0;

    do {

        int former = 1, next, flg = 1;

        for (int i : order){

            next = i;

            if (!vec[former][next]){
                flg = 0; break;
            }

            former = next;
        }

        if (flg) sum++;
    } while(next_permutation(order.begin(), order.end()));

    cout << sum << endl;
    return 0;

}