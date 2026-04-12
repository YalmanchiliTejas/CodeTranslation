#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int , int> P;
typedef pair<ll, ll> PL;
const int INT_INF = 2147483646;
const ll LL_INF = 9223372036854775807;

int n;
ll x;
ll length[51];
ll pnum[51];
ll ans;

void calc(ll len,int num){
    for(int i = num; i >= 0; i--){
        //cout << len << ' ' << ans << '!' << i << endl;
        if(length[i] <= len){
            ans += pnum[i];
            len -= length[i];
          //  cout << len << ' ' << ans << endl;
            if(len >= 1){
                ++ans;
                --len;
            }else{
                return;
            }
            calc(len,i);
            break;
        }
        --len;
    }
}

int main(){
    pnum[0] = 1;
    length[0] = 1;
    for(int i = 1; i <= 50; i++){
        pnum[i] = pnum[i-1]*2+1;
        length[i] = length[i-1]*2+3;
    }
    cin >> n >> x;
    calc(x,n);
    cout << ans << endl;
}