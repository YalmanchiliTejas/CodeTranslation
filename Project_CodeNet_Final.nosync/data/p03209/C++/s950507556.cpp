#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647);
static const ll LLINF = (9223372036854775807);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Printer{
    template<class T>
    void print(vector<T> v){
        rep(i, v.size()){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    template<class T>
    void print(vector<vector<T> > vv){
        rep(i, vv.size()){
            rep(j, vv[i].size()){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void print(pair<int, int> p){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
};

//--global--//



//----------//

ll solve(ll n, ll x, vector<vector<ll> > pos, vector<ll> paty){
    if(n == 1){
        ll dx[7] = {0LL, 0LL, 1LL, 2LL, 3LL, 3LL, 3LL};
        return dx[x];
    }
    ll res = 0;
    if(x > pos[n][0] && x < pos[n][1]){
        res += solve(n-1, x-1, pos, paty);
    }
    else if(x >= pos[n][1]){
        res += 1+paty[n-1]+solve(n-1, min(x, pos[n][2]-1) - pos[n][1], pos, paty);
    }
    return res;
}

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//

    ll n, x;
    cin >> n >> x;
    vector<vector<ll> > pos(51);
    vector<ll> paty(51);
    paty[1] = 3LL;
    rep2(i, 2, 51){
        paty[i] = paty[i-1]*2+1LL;
    }

    pos[1].push_back(1LL);
    pos[1].push_back(3LL);
    pos[1].push_back(5LL);
    rep2(i, 2, 51){
        pos[i].push_back(1LL);
        pos[i].push_back(1+pos[i-1][2]+1LL);
        pos[i].push_back(1+pos[i-1][2]*2+2LL);
    }
    //Printer::print(pos);

    //cout << solve(1, min(x, pos[n][1]), pos, paty) << endl;
    cout << solve(n, x, pos, paty) << endl;
    
    
    return 0;
}
