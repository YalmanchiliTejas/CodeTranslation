#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

char a[10][10];
ll h, w;
ll cnt = 0;

ll dfs(ll x, ll y){
    if(a[x+1][y] == '#'){
        cnt++;
        dfs(x+1, y);
    }else if(a[x][y+1] == '#'){
        cnt++;
        dfs(x, y+1);
    }
    return 0;
}

int main(){
    cin >> h >> w;
    ll charp = 0;

    fill(a[0] ,a[10], '.');

    for(long long y = 1; y <= h; y++){
        for(long long x = 1; x <= w; x++){
            cin >> a[x][y];
            if(a[x][y] == '#') charp++;
        }
    }

    dfs(1, 1);
    
    if(charp-1 == cnt) put("Possible");
    else put("Impossible");
    
    //rep(y,h) {rep(x,w) {cout << a[x][y];}cout << endl;}
}