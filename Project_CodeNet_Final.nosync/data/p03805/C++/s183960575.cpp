#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int (i)=(a);(i)<(int)(b);(i)++)
#define RREP(i,a,b) for(int (i)=(a);(i)>=(int)(b);(i)--)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;

bool g[10][10];

int main(){
    int n, m;
    cin >> n >> m;
    REP(i,0,m){
        int a, b;
        cin >> a >> b;
        a--; b--;
        g[a][b] = g[b][a] = true;
    }

    int path[10];
    REP(i,0,n){
        path[i] = i;
    }

    int ans = 0;
    do{
        if (path[0] != 0) break;
        bool flag = true;
        REP(i,1,n){
            if (!g[path[i - 1]][path[i]]){
                flag = false;
                break;
            }
        }
        if (flag) ans++;
        
    }while(next_permutation(path, path + n));
    
    cout << ans << endl;
    
    return 0;
}