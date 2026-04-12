#include <bits/stdc++.h>
using namespace std;
#define int long long

int n , x;
int l[55],p[55];

int dfs(int lev, int d){
    if(!lev) return 1;
    if(d==1) return 0;
    if(d==l[lev]) return p[lev];
    if(d==2+l[lev-1]) return p[lev-1] + 1;
    if(d<=1+l[lev-1]) return dfs(lev-1,d-1);
    return p[lev-1] + dfs(lev-1,d-2-l[lev-1]) + 1;
}

inline void solve(){    

    cin >> n >> x;
    l[0] = p[0] = 1; //レベル0の時、層は1枚パティも1枚
    for(int i = 1; i < n; i++) {
        l[i] = 2 * l[i-1] + 3; //1つ下のレベルが2つ、その他層が3つふえる
        p[i] = 2 * p[i-1] + 1;//そのときパティは2倍かつ1層ふえる
    }
    
    cout << dfs(n,x) << endl;

}
struct xyz{ xyz(){ cin.tie(0), ios::sync_with_stdio(false); cout <<fixed<<setprecision(12);};}xyzzy;signed main(){solve();return 0;}
