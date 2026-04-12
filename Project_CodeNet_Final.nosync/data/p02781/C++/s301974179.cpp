#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<vector>
#include<algorithm>
#include<functional>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<tuple>
#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define REP(i,x) for (int i=0;i<x;i++)
#define REPP(i,x,y) for (int i=x;i<=y;i++)
#define SI(x) scanf("%d",&x)
#define SL(x) scanf("%lld",&x)
#define MX3(x,y,z) max({x,y,z})
#define MX4(x,y,z,p) max({x,y,z,p})
#define MX5(x,y,z,p,q) max({x,y,z,p,q})
#define MN3(x,y,z) min({x,y,z})
#define MN4(x,y,z,p) min({x,y,z,p})
#define MN5(x,y,z,p,q) min({x,y,z,p,q})
#define amax(x,y) x=max(x,y)
#define amin(x,y) x=min(x,y)
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vb> vvb;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef tuple<int,int,int> ti;
typedef tuple<ll,ll,ll> tl;
// #####################################################################
char arr[200];
char tmp[200];

void solve() {

    scanf("%s", arr);
    int k;
    SI(k);
    int n = strlen(arr);
    int ans = 0;
    
    if(k == 1) {
        ans += 9 * (n - 1);
        ans += arr[0] - '0';
    }
    tmp[n] = 0;
    REP(i, n) tmp[i] = '0';

    if(k == 2) {

        if(n - 1 >= 2) {
            ans += (n-1) * (n-2) / 2 * 9 * 9;
        }
        if(n >= 2) {
            for(int i = 1 ; i <= 9 ; i++) {
                tmp[0] = i + '0';
                for(int z = 1 ; z < n ; z++) {
                    for(int j = 1 ; j <= 9 ; j++) {
                        tmp[z] = j + '0';
                        if(strcmp(arr, tmp) >= 0) {
                            ans++;
                        }
                    }
                    tmp[z] = '0';
                }
                tmp[0] = '0';
            }
        }
    }

    if(k == 3) {
        
        if(n - 1 >= 3) {
            ans += (n-1) * (n-2) * (n-3) / 6 * 9 * 9 * 9;

        }
        if(n >= 3) {
            for(int i = 1 ; i <= 9 ; i++) {
                tmp[0] = i + '0';
                for(int z = 1 ; z < n ; z++) {
                    for(int y = z+1 ; y < n ; y++) {
                        for(int j = 1 ; j <= 9 ; j++) {
                            tmp[z] = j + '0';
                            for(int kk = 1 ; kk <= 9 ; kk++) {
                                tmp[y] = kk + '0';
                                if(strcmp(arr, tmp) >= 0) {
                                    ans++;
                                }
                                tmp[y] = '0';
                            }
                            tmp[z] = '0';
                        }
                    }
                }
                tmp[0] = '0';
            }
        }
    }

    printf("%d\n", ans);
}

void init() {
    


}

int main () {
    init();
    solve();
    return 0;
}


