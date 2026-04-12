#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
template<typename T> void view(T cont) {std::cout << cont << std::endl;}
template<typename T> void view(T* cont, ll sz) {rep(i, sz) std::cout << cont[i] << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<T>& v) {for (const auto& f: v) std::cout << f << " "; std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v: vv) {view(v);}}
const long long INF = 1LL<<60;
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main(){
    int N, M; cin >> N >> M;
    vector<vector<int> > A(N, vector<int>(N, 0));
    rep(i, M) {
        int temp_a, temp_b; cin >> temp_a >> temp_b;
        A[temp_a - 1][temp_b - 1] = 1;
        A[temp_b - 1][temp_a - 1] = 1;
    }
    // rep(i, N) {
    //     rep(j, N) cout << A[i][j] << " ";
    //     cout << endl;
    // }

    vector<int> order;
    for (int i = 1; i < N; i++) {
        order.push_back(i);
    }
    // view(order);
    int count = 0;
    do {
        bool flag = false;
        
        int len = 0;
        for(int i = 0; i < N - 1; i++) {
            int from, to;
            if (i == 0) {
                from = 0;
            } else {
                from = order[i - 1];
            }
            to = order[i];
            // cout << "from: " << from << "to: " << to << endl;
            if (!A[from][to]) {
                break;
            } else {
                len++;
            }
        }
        // cout << 0 << " ";
        // rep(i, N - 1) {
        //     cout << order[i] << " ";
        // }
        // cout << endl;
        // cout << "length: " << len << endl;
        if (len == N - 1) {
            // cout << "success" << endl;
            count++;
        }
        // if (flag) count++;
    } while (next_permutation(order.begin(), order.end()));
    cout << count << endl;
}