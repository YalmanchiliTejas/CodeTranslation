#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i=0;i<(n);++i)
template<class T> inline void chmin(T &a, T b){if(a>=b)a=b;}
template<class T> inline void chmax(T &a, T b){if(a<=b)a=b;}
typedef long long ll;
const int INF = 1e9;

int N;
int H[30];

int main(){
    cin >> N;
    REP(i,N) cin >> H[i];

    int t = H[0];
    int ans = 1;
    for(int i = 1; i < N; ++i){
        if(t <= H[i]){
            ++ans;
            t = H[i];
        }
    }
    cout << ans << endl;
    return 0;
}