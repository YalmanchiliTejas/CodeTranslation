#include "bits/stdc++.h"
 
typedef long long ll;
#define int ll
#define fi first
#define se second
#define SORT(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/2

using namespace std;

int MOD = 1000000007;
int mp[10][10] = {0};
int ans = 0;
int n,m;

signed main(){
    // cerr << "aaaa" << endl;
    cin >> n >> m;

    
    rep(i,m){
        int a,b;
        cin >> a >> b;
        mp[a][b] = 1;
        mp[b][a] = 1;
    }
    int x[7] = {2,3,4,5,6,7,8};

    // cerr < ans << endl;

    do{
        int c = 1;
        rep(i,n-1){
            if(i == 0){
                if(mp[1][x[i]] == 0) c = 0;
            }else{
                if(mp[x[i-1]][x[i]] == 0)c = 0;
            }
        }
        if(c == 1)ans++;
        // if(c == 1){
        //     rep(i,n-1)cerr << x[i];
        //     cerr << endl;
        // }
    }while(next_permutation(x,x+n-1));

    
    cout << ans << endl;

    return 0;
}
// g++ -std=c++14 code1.cpp
// rm -r -f test;oj dl 