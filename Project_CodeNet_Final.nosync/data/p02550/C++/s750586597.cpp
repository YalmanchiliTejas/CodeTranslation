#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    ll n, x, m;
    cin >> n >> x >> m;

    vector<int> exist(m, 0);
    exist[x] = 1;
    ll a = x, sum = x;
    ll am, rep = 0;
    for(int i = 2; i <= n; ++i){
        am = (a * a) % m;
        if(exist[am] != 0){
            rep = i;
            break;
        }else{
            a = am;
            sum += am;
            exist[am] = i;
        }
    }

    if(rep == 0){
        cout << sum << "\n";
        return 0;
    }

    ll rep_sum = 0;
    for(int i = exist[am]; i < rep; ++i){
        am = (am * am) % m;
        rep_sum += am;
    }
    sum -= rep_sum;


    n -= exist[am] - 1;
    ll am2 = am;
    ll ans = sum + n / (rep - exist[am]) * rep_sum;
    for(int i = 0; i < n % (rep - exist[am]); ++i){
        ans += am2;
        am2 = (am2 * am2) % m;
        if(am2 < 0) am2 += m;
    }

    cout << ans << "\n";

    return 0;
}
