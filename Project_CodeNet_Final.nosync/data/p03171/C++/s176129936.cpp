#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
using ll = long long;
using graph = std::vector<std::vector<ll>>;
using wGraph = std::vector<std::vector<std::pair<ll,ll>>>;
#define rep(i,n) for (int i=0; i < int(n); i++)

using namespace std;
vector<ll> InputVec(ll N){
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    return A;
}
void OutputVec(vector<ll> A){
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << ",";
    }
    cout << endl;
}
vector<vector<ll>> InputVec2d(ll H,ll W){
    vector<vector<ll>> A(H);
    for (int yi = 0; yi < H; ++yi) {
        A[yi] = vector<ll>(W);
    }
    for (int yi = 0; yi < H; ++yi) {
        for (int xi = 0; xi < W; ++xi) {
            cin >> A[yi][xi];
        }
    }
}

void OutputVec2d(vector<vector<ll>> A){
    for (int yi = 0; yi < A.size(); ++yi) {
        for (int xi = 0; xi < A[yi].size(); ++xi) {
            cout << A[yi][xi] << ",";
        }
        cout << endl;
    }
}
vector<vector<ll>> memo(3005);
vector<ll> a;
void init(){
    for (int i = 0; i < 3005; ++i) {
        memo[i] = vector<ll>(3005);
        for (int j = 0; j < 3005; ++j) {
            memo[i][j] = -1;
        }
    }
}

ll solve(ll si,ll gi){
    if(memo[si][gi] != -1){
        return memo[si][gi];
    }
    if(si == gi){
        memo[si][gi] = a[si];
        return memo[si][gi];
    }
    memo[si][gi] = max(a[si] - solve(si + 1,gi),a[gi] - solve(si,gi - 1));
    return memo[si][gi];
}

int main() {
    ll N;
    cin >> N;
    a = InputVec(N);
    init();
    solve(0,N-1);
    //OutputVec2d(memo);
    for (int yi = 0; yi < N + 1; ++yi) {
        for (int xi = 0; xi < N + 1; ++xi) {
            //cout << memo[yi][xi] << ",";
        }
        //cout << endl;
    }

    cout << memo[0][N-1] << endl;

}
