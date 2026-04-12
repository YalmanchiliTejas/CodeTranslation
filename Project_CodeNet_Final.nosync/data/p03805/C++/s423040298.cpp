#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;

typedef long long ll;

const int INF = 1 << 30;
const ll LLINF = 1LL << 62;

int mod = 1000000007;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M; cin >> N >> M;
    int mat[N][N]{};
    int ans = 0;
    rep(i, M){
        int a, b; cin >> a >> b;
        mat[a-1][b-1] = mat[b-1][a-1] = 1;
    }
    vector<int> vec; rep(i, N) vec.push_back(i);
    do{
        bool ok = true;
        rep(i, N-1){
            if(mat[vec[i]][vec[i+1]] == 0) ok = false;
        }
        if(ok) ans++;
    }while(next_permutation(vec.begin()+1, vec.end()));
    cout << ans << endl;
    return 0;
}