#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647 >> 1); // 10^9 + 5000
static const ll LLINF = (9223372036854775807 >> 1);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Kunitaka{
    template<
        typename TYPE,
        std::size_t SIZE
    >
    std::size_t array_length(const TYPE (&array)[SIZE])
    {
        return SIZE;
    }
}
using namespace Kunitaka;
namespace Printer{
    void br(){
        cout << endl;
    }

    void loop_cnt(int i){
        cout << "i = " << i << endl;
    }

    void loop_cnt(int i, int j){
        cout << "i = " << i << ", " << "j = " << j << endl;
    }

    template<class T>
    void print(T x){
        cout << x << endl;
    }

    template<class T, class S>
    void print(T x, S y){
        cout << x << "," << y << endl;
    }

    template<class T, class S, class U>
    void print(T x, S y, U z){
        cout << x << "," << y << "," << z << endl;
    }

    template<class T, class S>
    void print(pair<T, S> p){
        cout << p.first << ", " << p.second << endl;
    }

    template<
        typename TYPE,
        std::size_t SIZE
    >
    void print(const TYPE (&array)[SIZE]){
        int lim = array_length(array);
        for(int i=0; i<lim; i++){
            if(i) cout << " ";
            cout << array[i];
        }
        cout << endl;
    }

    template<class S>
    void print(vector<S> v){
        for(int i=0; i<v.size(); i++){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    template<class S>
    void print(vector<vector<S> > vv){
        for(int i=0; i<vv.size(); i++){
            for(int j=0; j<vv[i].size(); j++){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void yesno(bool x){
        if(x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
};
using namespace Printer;

ll dp[101][4][2][2];

int calc(bool not_zero, int a){
    if(not_zero){
        return a + 1;
    }
    return a;
}

ll solve(string N, int K, int d, int not_zero_num, bool tight, bool not_zero){
    int dx[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int lim = 9; // 0 ~ 9
    if(tight) lim = N[d] - '0';
    if(not_zero_num == K) return 1;
    if(d == N.size()) return 0;

    ll &sum = dp[d][not_zero_num][tight][not_zero];

    //すでに値が決まって入れば、これ以上探索する必要はないためこの時点で返してあげる
    if (sum != -1) return sum;

    sum = 0;
    // 0
    sum += solve(N, K, d+1, not_zero_num, (0 == lim) && (tight), not_zero);
    // 1~lim
    if(lim > 0){
        if(tight){
            // 1 ~ lim-1, lim == N[d] - '0'
            if(lim == 1){
                sum += solve(N, K, d+1, not_zero_num+1, true, true);
            }
            else{
                sum += solve(N, K, d+1, not_zero_num+1, false, true) * (lim - 1);
                sum += solve(N, K, d+1, not_zero_num+1, true, true);
            }
        }
        else{
            // 1 ~ lim
            sum += solve(N, K, d+1, not_zero_num+1, false, true) * lim;
        }
        
    }
    // lim == N[d] - '0'
    return sum;
}

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//

    // variable
    ll ans = 0;

    // input
    cout << fixed << setprecision(10);
    string N; cin >> N;
    int K; cin >> K;

    // solve
    memset(dp, -1, sizeof(dp));
    print(solve(N, K, 0, 0, true, false));
    
    return 0;
}
