#include<iostream>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#include<sstream>
#include<queue>
#include<functional>
#include<bitset>
#include<cstdio>
#include<iomanip>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include <string.h>

using ll = long long;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, x) for(int i=1;i<=(int)(x);i++)
#define rrep(i, x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i, x) for(int i=(int)(x);i>0;i--)
#define all(x) (x).begin(),(x).end()
#define m0(x) memset(x,0,sizeof(x))
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define vpi vector<pair<int,int>>
#define mod 1000000007
#define put2darr(arr, row, col) rep(i, row) { rep(j, col) { printf("%18d", arr[i][j]); } cout << endl; }

using namespace std;

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return 1; } return 0; }

/* 1..10
 * rep:   0 1 2 3 4 5 6 7 8 9
 * reps:  1 2 3 4 5 6 7 8 9 10
 * rrep:  9 8 7 6 5 4 3 2 1 0
 * rreps: 10 9 8 7 6 5 4 3 2 1
 */
int h[20];
int main(){
    int n;
    cin >> n;
    rep(i, n) cin >> h[i];
    int ans = 0;
    int mx = 0;
    rep(i, n){
        if(mx <= h[i]){
            ans++;
            mx = h[i];
        }
    }
    cout << ans <<endl;
}

