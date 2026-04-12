#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

int N;
string S, ans;
string pat[4] ={ "SS", "SW", "WS", "WW" };

signed main(){
    cin >> N >> S;

    rep(i, 4){
        ans = pat[i];
        for(int j=2; j<N; j++){
            if(ans[j-1] == 'S'){
                if(S[j-1] == 'o') ans += ans[j-2];
                else ans += (ans[j-2] == 'S' ? 'W' : 'S');
            }
            else{
                if(S[j-1] == 'x') ans += ans[j-2];
                else ans += (ans[j-2] == 'S' ? 'W' : 'S');
            }
        }
        bool flg = true;
        rep(j, N){
            if(ans[j] == 'S'){
                if(S[j] == 'o') flg &= (ans[(j-1+N)%N] == ans[(j+1)%N]);
                else flg &= (ans[(j-1+N)%N] != ans[(j+1)%N]);
            }
            else{
                if(S[j] == 'x') flg &= (ans[(j-1+N)%N] == ans[(j+1)%N]);
                else flg &= (ans[(j-1+N)%N] != ans[(j+1)%N]);
            }
        }
        if(flg){
            cout << ans << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}