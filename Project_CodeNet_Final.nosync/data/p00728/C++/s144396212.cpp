#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N;
    cin >> N;
    while(N){
        int sum = 0,a,maxi = 0,mini = INF;
        rep(i,0,N){
            cin >> a;
            sum += a;
            maxi = max(maxi, a);
            mini = min(mini, a);
        }
        sum -= (maxi + mini);
        cout << sum / (N - 2) << endl;
        cin >> N;
    }
}
