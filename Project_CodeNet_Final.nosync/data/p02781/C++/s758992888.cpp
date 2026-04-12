#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class T,class U> using Pa = pair<T,U>;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

ll dp[110][10][4][2] = {};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;
    int K;
    cin >> S >> K;
    int N = S.size();
    
    dp[0][0][0][0] = 1;
    for(int i=0;i<N;i++) for(int j=0;j<10;j++) for(int k=0;k<=K;k++) for(int l=0;l<2;l++){
        for(int nj=0;nj<10;nj++){
            if(!l && (S[i]-'0')<nj) continue;
            int nk = k+(nj!=0);
            if(nk>K) continue;
            bool nl = (l || nj<(S[i]-'0'));
            dp[i+1][nj][nk][nl] += dp[i][j][k][l];
        }
    }
    ll ans = 0;
    for(int j=0;j<10;j++) for(int l=0;l<2;l++) ans += dp[N][j][K][l];
    cout << ans << "\n";
}