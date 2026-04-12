#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
#define v(i) vector<i>
#define vv(i) vector<vector<i>>
// cin.eof() 入力個数の問題
// int num = atoi(string.c_str()); 文字列の整数変換
int keta(ll n){int ans=0;while(n>0){n /= 10; ans++;}return ans;}
ll _pow(ll a,ll b){ll ans = 1;rep(i,b){ ans *= a;}return ans;}

int main() {
int h,w; cin>>h>>w;
string a[h];
rep(i,h) cin>>a[i];
map<int,bool> H,W;
rep(i,h){
    bool flag = true;
    rep(j,w){
        if(a[i][j] == '#') flag = false;
    }
    if(flag){
        H[i] = true;
    }
}
rep(i,w){
    bool flag = true;
    rep(j,h){
        if(a[j][i] == '#') flag = false;
    }
    if(flag){
        W[i] = true;
    }
}

rep(i,h){if(H[i]) continue;
    rep(j,w){
        if(W[j]) continue;
        cout<<a[i][j];
    }
    cout<<endl;
}

    return 0;
}
