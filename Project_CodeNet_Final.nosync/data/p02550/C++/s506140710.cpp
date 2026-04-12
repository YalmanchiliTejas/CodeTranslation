#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
using ll = long long int;

ll solve(ll n, ll x, ll m){
    vector<int> isexist(m, 0);
    ll cur = x;
    int loopstart;
    int loopstepnum = -1;
    int initstep;
    for(int i = 1; i <= m+10; i++){
        if(isexist[cur] != 0){
            loopstart = cur;
            initstep = isexist[cur]-1;
            loopstepnum = i-isexist[cur];
            break;
        }else{
            isexist[cur] = i;
            cur = cur*cur;
            cur %= m;
        }
    }

    if(loopstepnum != -1){
        vector<ll> loopsum(loopstepnum+1, 0);
        {
            ll curnum = loopstart;
            for(int i = 1; i <= loopstepnum; i++){
                loopsum[i] = loopsum[i-1]+curnum;
                curnum = (curnum*curnum)%m;
            }
        }

        ll ans = 0;
        ll cur2 = x;
        for(int i = 0; i < min((ll)initstep, n); i++){
            ans += cur2;
            cur2 = (cur2*cur2)%m;
        }
        
        ans += loopsum[loopstepnum] * ((n-initstep)/loopstepnum);
        int laststep = (n-initstep) % loopstepnum;
        ans += loopsum[laststep];
        return ans;
    }else{
        return 0;
    }
}

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    
    cout << solve(n, x, m) << endl;
    return 0;
}