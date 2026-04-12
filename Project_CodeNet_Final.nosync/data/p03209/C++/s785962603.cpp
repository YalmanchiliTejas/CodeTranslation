#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;
ll bans[52];
ll all[52];

ll solve(ll n, ll x){
    if (n == 0){
        if(x <= 0){
            return 0;
        }
        else{
            return 1;
        }
    }
    else if(x <= 1 + all[n-1]){
        return solve(n-1,x-1);
    }
    else {
        return bans[n-1]+1+solve(n-1,x-2-all[n-1]);
    }


}


int main(){
    ll n,x;
    cin >> n >> x;
    bans[0] = 1;
    all[0] = 1;
    for(int i = 1;i < 51;i++){
        bans[i] = 2 * bans[i-1] + 1;
        all[i] = 2 * all[i-1] + 3;
    }
    ll ans;
    ans = solve(n,x);
    cout << ans << endl;

    
}