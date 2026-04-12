#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <string>

#define reps(i,s,n) for(long long (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using vi = vector<int> ;
using vl = vector<ll>;

int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    ll tmp = x;
    vector<bool> flag(100010,false);
    vl vec(100010,0);
    vec[0] = tmp;
    flag[tmp] = true;

    ll total_len = 0;
    ll l_start = 0;

    reps(i,1,100010){
        tmp = (tmp*tmp) % m;
        vec[i] = tmp;
        if(!flag[tmp]) flag[tmp]=true;
        else {
            total_len = i;
            break;
        }
    }
    
    rep(i,100010){
        if(vec[i] == vec[total_len]){
            l_start = i;
            break;
        }
    }

    ll len = total_len-l_start;
    ll ans = 0;
    ll lsum = 0;
    
    rep(i,l_start){
        ans += vec[i];
    }
    reps(i,l_start, total_len){
        lsum = (lsum+vec[i]);
    }

    ll lcnt = (n - l_start) / len;
    ans += lcnt * lsum;
    ll tmp2 = (n - l_start) % len;
    
    reps(i,l_start,l_start+tmp2){
        ans += vec[i];
    }

    cout << ans << endl;
    return 0;
}