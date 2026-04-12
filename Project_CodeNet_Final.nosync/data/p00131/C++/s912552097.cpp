#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int lcm(int a, int b){
    return a/gcd(a,b)*b;
}
int n = 10;
bool in(int a, int b){
    if(a < 0 || a >= n || b < 0 || b >= n)return false;
    return true;
}
int dx[] = {0,0,1,0,-1};
int dy[] = {0,1,0,-1,0};

signed main(void) {
    int num;
    cin >> num;
    while(num--){
        vvi a(n,vi(n));
        rep(i,n)rep(j,n)cin >> a[i][j];
        rep(bit, 1<<n){
            vvi t = a;
            vvi ans(n,vi(n,0));
            rep(i,n)if(bit&(1<<i)){
                ans[0][i]++;
                rep(j,5){
                    int x = 0 + dx[j];
                    int y = i + dy[j];
                    if(in(x,y))t[x][y] ^= 1;
                }
            }
            rep(i,n-1)rep(j,n)if(t[i][j]){
                ans[i+1][j]++;
                rep(k,5){
                    int x = i+1 + dx[k];
                    int y = j + dy[k];
                    if(in(x,y))t[x][y] ^= 1;
                }
            }
            bool c = true;
            rep(j,n)if(t[n-1][j])c = false;
            if(c){
                rep(i,n)rep(j,n)cout << ans[i][j] << " \n"[j == n-1];
            }
        }
        vvi ans(n,vi(n,0));
    }
}

