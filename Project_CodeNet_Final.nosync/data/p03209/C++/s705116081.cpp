#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
//priority_queue<int> pque;
//priority_queue<int, vector<int>, greater<int>> pque;
ll INFL = 1000000000000000010;//10^18 = 2^60
int INF = 2000000000;//10^9
ll MOD  = 1000000007;

int main(void){
    int N;
    ll X;
    cin >> N >> X;
    ll S = pow(2, N+2) - 3;
    ll ans = 0;
    ll cnt = 0;
    while(1){
        cnt++;
        if(cnt > 100000)break;
        if(X == -1)break;
        if(S / 2 + 1 < X){
            ans += pow(2, N);
            S -= 3;
            S /= 2;
            X -= S + 2;
            N--;
        }else if(S / 2 + 1 > X){
            S -= 3;
            S /= 2;
            X--;
            N--;
        }else{
            ans += pow(2, N);
            break;
        }
    }
    
    cout << ans << endl;
    
}
