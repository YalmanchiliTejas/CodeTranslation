#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

const ll mod = 1000000007;

int main(){
    ll n, x, m;
    cin >> n >> x >> m;
    ll modn[m];
    fill(modn, modn + m, -1);
    ll a = x % m;
    modn[a] = 1;
    ll loop = 0;
    ll cnt = 2;
    while(cnt <= n){
        a = (a * a) % m;
        if(modn[a] != -1){
            loop = cnt - modn[a];
            break;
        }else{
            modn[a] = cnt;
            cnt++;
        }
    }

    ll ans = 0;
    if(loop == 0){
        rep(i, m){
            if(modn[i] == -1) continue;
            else ans += i;
        }
    }else{
        ll loop_num = (n - modn[a]) / loop;
        ll p = (n - modn[a]) % loop;
        rep(i, m){
            if(modn[i] == -1) continue;
            if(modn[a] > modn[i]) ans += i;
            else{
                if(modn[a] + p >= modn[i]){
                    ans += i * (loop_num + 1);
                }else{
                    ans += i * loop_num;
                }
            }
        }
    }

    cout << ans << endl;
}