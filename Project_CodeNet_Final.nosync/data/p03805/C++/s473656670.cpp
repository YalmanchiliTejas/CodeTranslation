#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
using namespace std;
using ll = int64_t;
using vi = vector<int>;
using vvi = vector<vi>;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > A(m);
    rep(i, m) {
        cin >> A[i].first >> A[i].second;
    }
    vi vec(n);
    rep(i, n) {
        vec[i] = i+1;
    }
    int C=0;
    do {
        if(vec[0] != 1) continue;
        bool able = true;
        rep(i, n-1){
            bool OK = false;
            rep(j, m) {
                if(A[j] == make_pair(vec[i], vec[i+1]) || A[j] == make_pair(vec[i+1], vec[i])) {
                    OK = true;
                    break;
                }
            }
            if(!OK) {
                able = false;
                break;
            }
        }
        if(able) {
            ++C;
        }
    } while(next_permutation(vec.begin(), vec.end()));
    cout << C << endl;
}