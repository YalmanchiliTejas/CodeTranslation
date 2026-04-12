#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pb push_back
#define all(v) (v).begin() , (v).end()
#define popcnt(x) __builtin_popcount(x)
#define inf 0x3f3f3f3f
#define watch(x) cout << (#x) << " is " << (x) << endl
#define F first
#define S second

using namespace std;
using namespace __gnu_pbds;
typedef long long  ll;

template <typename T>
using ordered_set = tree<T, null_type, less<T> , rb_tree_tag, tree_order_statistics_node_update>;

const double EPS = 1e-9;
const double pi = acos(-1.0);

int dx[] = {0 , 0 , 1 , -1 , 1 , 1 , -1 , -1};
int dy[] = {1 ,-1 , 0 , 0 , -1 , 1 ,  1 , -1};


int main(){
    int n , m;
    cin >> n >> m;

    char g[n][m];
    for(int i = 0 ; i < n ; ++i){
        for(int j = 0 ; j < m ; ++j)cin >> g[i][j];
    }

    bool f[n][m];
    memset(f , 0 , sizeof f);
    for(int i = 0 ; i < n ; ++i){
        bool ok = true;
        for(int j =  0 ; j< m ; ++j){
            ok &= g[i][j] == '.';
        }

        if(ok){
            for(int j =  0 ; j< m ; ++j){
//                cout << i << ' ' << j << endl;
                f[i][j] = true;
            }
        }
    }
//    watch(1);

    for(int i = 0 ; i < m ; ++i){
        bool ok = true;
        for(int j = 0 ; j< n ; ++j){
            ok &= g[j][i] == '.';
        }

        if(ok){
            for(int j =  0 ; j< n ; ++j){
//                cout << i << ' ' << j << endl;
                f[j][i] = true;
            }
        }
    }

    for(int i = 0 ; i < n ; ++i){
        bool ok = false;
        for(int j = 0 ; j < m ; ++j){
//            cout << i << ' ' << j << endl;
//            cout << f[i][j] << endl;
            if(!f[i][j])cout << g[i][j] , ok = true;
        }
        if(ok)cout << endl;
    }
}
