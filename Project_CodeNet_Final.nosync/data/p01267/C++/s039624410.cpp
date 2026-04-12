#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,A,B,C,X;
    cin >> N >> A >> B >> C >> X;
    while(N){
        int cnt = 0;
        rep(i,0,N){
            int y;
            cin >> y;
            while(X != y && cnt <= 10000){
                X = (A * X + B) % C;
                cnt++;
            }
            X = (A * X + B) % C;
            cnt++;  
        }
        cnt--;
        if(cnt <= 10000)cout << cnt << endl;
        else            cout << -1 << endl;
        cin >> N >> A >> B >> C >> X;
    }
}
