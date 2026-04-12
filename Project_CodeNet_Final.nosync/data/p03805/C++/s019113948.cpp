#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
    int n, m;
    cin >> n >> m;
    vvi G(n);
    rep(i,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vi vec(n);
    rep(i,n) vec[i] = i;
    int cnt = 0;
    do {
        // rep(i,n){
        //     printf("%d ", vec[i]);
        // }
        // printf("\n");

        rep(i,n-1){
            bool flag = false;
            for (auto nv : G[vec[i]]){
                if (nv == vec[i+1]) flag = true;
            }
            if (!flag) break;
            if (i == n-2) cnt++;
        }
    } while (next_permutation(vec.begin() + 1, vec.end()));

    cout << cnt << endl;
    return 0;
}
