#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 998244353;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=100005;
using namespace std;

int main(){
    ll n,x,m;
    cin >> n >> x >> m;
    vector<ll> md(100001,-1);
    vector<ll> ln;
    ll st_id, end_id, cnt;

    for(ll i = x; ; i = i*i % m){
        ln.push_back(i);
        if(md[i] == -1){
            md[i] = 1;
        } else {
            for(ll j = 0; j < ln.size(); j++){
                if(ln[j] == i){
                    st_id = j;
                    break;
                }
            }
            cnt = ln.size() - st_id - 1;
            break;
        }
    }
    ll before_sum[st_id+1];
    before_sum[0] = 0;
    for(int i = 1; i <= st_id; i++){
        before_sum[i] = before_sum[i-1] + ln[i-1];
    }
    ll loop_sum[cnt+1];
    loop_sum[0] = 0;
    for(int i = 1; i <= cnt; i++){
        loop_sum[i] = loop_sum[i-1] + ln[st_id+i-1];
    }

    ll ans;
    if(n <= st_id){
        ans = before_sum[n];
    } else {
        n -= st_id;
        ans = before_sum[st_id];
        if(n >= cnt) ans += loop_sum[cnt]*(n/cnt);
        ans += loop_sum[(n%cnt)];
    }

    cout << ans << endl;

    return 0;
}