#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
void solve(int N,int L,int R){
    vector<int> V(N);
    rep(i,0,N)cin >> V[i];
    auto judge = [&](int x) -> bool{
        rep(i,0,N){
            if(x % V[i] == 0)return i%2 == 0;
        }
        return N % 2 == 0;
    };
    int cnt = 0;
    rep(i,L,R+1)cnt += judge(i);
    cout << cnt << endl;
}
main(){
    int N,L,R;
    cin >> N >> L >> R;
    while(N){
        solve(N,L,R);
        cin >> N >> L >> R;
    }
}
