#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
     
using namespace std;
     
typedef long long ll;
typedef pair<ll, int> pii;
     
#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
     
mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 10;
char h[N][N];

int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 1 ; i <= n; i ++ ){
        for(int j = 1 ; j <= m ; j ++ ){
            cin >> h[i][j];
            cnt += (h[i][j]=='#');
        }
    }
    int ci=1,cj=1;
    int dir = 0;
    int vis = 1;
    while(ci!=n || cj!=m){
        dir = 0;
        dir += (h[ci+1][cj] == '#');
        dir += (h[ci][cj+1] == '#');
        vis ++ ;
        if(dir!=1){
            cout << "Impossible\n";
            return 0;
        }
        if(h[ci+1][cj] == '#')
            ci++;
        else if(h[ci][cj+1] == '#')
            cj++;
    }
    if(ci==n && cj == m && cnt == vis)
        cout << "Possible\n";
    else
        cout << "Impossible\n";
    return 0;
}