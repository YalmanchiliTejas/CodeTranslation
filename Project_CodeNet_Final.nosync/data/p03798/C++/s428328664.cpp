#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 60;
const int INF = 1e9 + 7;

vector<vector<ll>> g(100010); 
vector<ll> dist(100010);

int main(){
    ll n;
    string s;
    cin >> n >> s;

    char fst[] = {'S', 'W'};
    char snd[] = {'S', 'W'};

    rep(i, 2)rep(j, 2){
        string res = "";

        res += fst[i];
        res += snd[j];

        //右隣の動物を決めていく
        for(ll k = 1; k < n-1; ++k){
            if((res[k] == 'S' && s[k] == 'o') || (res[k] == 'W') && s[k] == 'x'){
                res += res[k-1];
            }
            else {
                if(res[k-1] == 'S')res += 'W';
                else res += 'S';
            }
        }
        

        //はじめの動物をもとに、矛盾していないか調べる
        if((res[0] == 'S' && s[0] == 'o') || (res[0] == 'W') && s[0] == 'x'){
            if(res[1] != res[n-1])continue;
        }
        else {
            if(res[1] == res[n-1])continue;
        }

        //最後の動物をもとに、矛盾していないか調べる
        if((res[n-1] == 'S' && s[n-1] == 'o') || (res[n-1] == 'W') && s[n-1] == 'x'){
            if(res[0] != res[n-2])continue;
        }
        else {
            if(res[0] == res[n-2])continue;
        }

        cout << res << endl;
        return 0;
    }

    cout << -1 << endl;
}